class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans(n);
        vector<int> prefix(n), suffix(n);
        prefix[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = max(prefix[i - 1], nums[i]);
        }
        suffix[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = min(suffix[i + 1], nums[i]);
        }
        ans[n - 1] = prefix[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            int num = prefix[i];
            int res = num;
            if (suffix[i + 1] < prefix[i]) {
                res = ans[i + 1];
            }
            ans[i] = res;
        }
        return ans;
    }
};
// 3 2 8 2
// 3 3 8 8
//