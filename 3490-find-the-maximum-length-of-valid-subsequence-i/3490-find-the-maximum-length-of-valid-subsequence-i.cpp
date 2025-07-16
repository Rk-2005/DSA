class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();

        for (auto& it : nums) {
            it = it % 2;
        }
        int c0 = 0, c1 = 0, c01 = 0, c10 = 0;
        int ans = 0;
        bool is = 0;
        bool is2 = 0;
        bool foundans = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                is2 = 1;
                if (is) {
                    is = 0;
                    c10 += 2;
                }
                ans = max(ans, c01 + 1);
                
                c0++;
            } else {
                if (is2 == 1) {

                    c01 += 2;
                    is2 = 0;
                }
                ans = max(ans, c10 + 1);
                is = 1;
                c1++;
            }
        }
        return max({c0, c1, c10, c01, ans});
    }
};
// 0 1 0