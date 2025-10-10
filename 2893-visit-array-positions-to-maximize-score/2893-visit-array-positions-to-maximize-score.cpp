class Solution {
public:
    long long a;
    long long dp[100001][2];
    long long solve(vector<int>& nums, int i, bool pos) {
    if (i == nums.size()) return 0;
    if (dp[i][pos] != -1) return dp[i][pos];

    long long nottake = solve(nums, i + 1, pos);

    long long take;
    if (nums[i] % 2 == pos)
        take = nums[i] + solve(nums, i + 1, pos);
    else
        take = nums[i] - a + solve(nums, i + 1, !pos);

    return dp[i][pos] = max(take, nottake);
}

    long long maxScore(vector<int>& nums, int x) {
        long long n = nums.size();
        a = x;
        memset(dp, -1, sizeof(dp));
        long long ans = solve(nums, 1, nums[0] % 2) + nums[0];
        return ans;
    }
};

//