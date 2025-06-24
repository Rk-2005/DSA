class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();

        vector<int> ans;
        int r = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == key) {

                int l = max(r , i - k);
                r = min(n - 1, i + k)+1;
                for (int j = l; j < r; j++) {
                    ans.push_back(j);
                }
            }
        }
        return ans;
    }
};
// 0 1 2 3 4
// 2 2 2 2 2
// l=2 r = 2