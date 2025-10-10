class Solution {
public:
    const int mod = 1e9 + 7;
    long long dp[100001][3][4];

    int solve(vector<int>& nums, int i, bool even, int c) {

        if (i >= nums.size()) {
            return 0;
        }
        if (dp[i][even][c] != -1) {
            return dp[i][even][c];
        }
        int take = 0;

        if (i == 0 || (nums[i] % 2 == even && c < 2)) {
            take = 1 + solve(nums, i + 1, nums[i] % 2, c + 1); // bekar case
        } else if (nums[i] % 2 != even) {
            take = 1 + solve(nums, i + 1, nums[i] % 2, 1);
        }

        int nottake = solve(nums, i + 1, even, c);

        return dp[i][even][c] = (take + nottake) % mod;
    }
    int countStableSubsequences(vector<int>& nums) {
        int n = nums.size();
        memset(dp, -1, sizeof(dp));
        return solve(nums, 0, 0, 0) % mod;
    }
};
// 2 3 4 2
// 2 2 4