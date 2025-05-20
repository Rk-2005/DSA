class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int m = queries.size();
        vector<int> temp(n + 1);
        for (auto& it : queries) {
            int x = it[0];
            int y = it[1];
            temp[x] += -1;
            temp[y + 1] += 1;
        }

        for (int i = 1; i < temp.size(); i++) {
            temp[i] += temp[i - 1];
        }

        for (int i = 0; i < n; i++) {
            if(abs(temp[i])<nums[i])return 0;
        }
        
        
        return true;
    }
};