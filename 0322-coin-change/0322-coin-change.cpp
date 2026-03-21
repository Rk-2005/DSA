
class Solution {
public:
    int dp[13][10004];
    long long solve(vector<int>& coins, int amount, int n, int idx) {
        // Base case: if we have considered all coins
        if (idx >= n) {
            if (amount == 0) {
                return 0;
            }
            return INT_MAX;
        }
        if(dp[idx][amount]!=-1)return dp[idx][amount];

        // If the amount becomes negative, it's not valid
        if (amount < 0)
            return INT_MAX;

        // Try to take the current coin
        long long take = INT_MAX;
        if (coins[idx] <= amount) {
            take = 1+ solve(coins, amount - coins[idx], n, idx);
        }

        // Try not to take the current coin
        long long nottake = solve(coins, amount, n, idx + 1);

        // Return the minimum of taking or not taking the coin
        return dp[idx][amount]= min(take, nottake);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        
        memset(dp,-1,sizeof(dp));
        // If no solution is found, return -1
        return ( solve(coins, amount, n, 0) == INT_MAX) ? -1 :  solve(coins, amount, n, 0);;
    }
};
