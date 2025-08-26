class Solution {
public:
    int coinChange(vector<int>& coins, int k) {
        int n = coins.size();
        vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, INT_MAX));

        for (int i = 0; i <= k; i++) {
            if (i % coins[0] == 0) {
                dp[0][i] = i / coins[0];
            }
        }

        for (int i = 1; i < n; i++) {
            long long num = coins[i];

            for (int j = 0; j <= k; j++) {

                dp[i][j] = dp[i - 1][j];

                if(j>=num){
                    dp[i][j] = min(dp[i][j],1+dp[i][j-num]);
                }

            }
        }
        return (dp[n - 1][k] == INT_MAX ? -1 : dp[n - 1][k]);
    }
};
// dp[]