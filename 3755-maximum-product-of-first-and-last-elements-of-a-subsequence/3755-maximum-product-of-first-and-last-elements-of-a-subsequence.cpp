class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {
        int n = nums.size();
        vector<int> PosMax(n, 0), NegMax(n, 0);

        PosMax[n - 1] = nums[n - 1];

        NegMax[n - 1] = nums[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            PosMax[i] = max(PosMax[i + 1], nums[i]);
            NegMax[i] = min(NegMax[i + 1], nums[i]);
        }

        long long ans = LLONG_MIN;

        for (int i = 0; i <= n - m; i++) {
            long long num = nums[i];
            if (num > 0) {
                ans = max(ans, num * PosMax[i + m - 1]);
            } else
                ans = max(ans, num * NegMax[i + m - 1]);
        }
        return ans;
    }
};