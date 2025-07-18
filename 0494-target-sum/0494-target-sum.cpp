class Solution {
public:
   int dp[21][2001];
    int solve(vector<int>& nums, int target, int i, int sum) {
        if (i >= nums.size()) {
            if (sum == target)
                return 1;

            return 0;
        }
    
        if(dp[i][sum+1000]!=-1)return dp[i][sum+1000];

        int take = solve(nums, target, i + 1, sum + nums[i]);
        int nottake = solve(nums, target, i + 1, sum - nums[i]);
        return dp[i][sum+1000]=take + nottake;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        memset(dp,-1,sizeof(dp));

        return solve(nums, target, 0, 0);
    }
};