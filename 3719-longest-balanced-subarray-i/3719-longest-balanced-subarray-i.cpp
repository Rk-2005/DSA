class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();

        int ans = 0;

        for (int i = 0; i < n; i++) {
            int e = 0, o = 0;
            unordered_set<int> st;
            for (int j = i; j < n; j++) {
                if (st.find(nums[j]) == st.end()) {
                    
                
                st.insert(nums[j]);
                if (nums[j] % 2 == 0) {
                    e++;
                } else {
                    o++;
                }
                }
                if (o == e) {
                    ans = max(ans, j - i + 1);
                }
            }
        }
        return ans;
    }
};