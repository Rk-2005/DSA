class Solution {
public:
     long long  dp[1001][501][3];
    const long long mod = -1e17;
    long long solve(long long i, vector<int>& prices, long long k, long long s) {
        if (i >= prices.size() || k == 0) {
            if(s==0)return 0;
            return mod;
        }
        if(dp[i][k][s]!=-1)return dp[i][k][s];
        long long profit = LLONG_MIN;
        if (s == 0) {
            long long nottake = solve(i + 1, prices, k, s);
            long long take =  solve(i + 1, prices, k, 1);
            if(take!=mod){
                take+=-prices[i];
            }
            long long shortt = solve(i + 1, prices, k, 2);
            if(shortt!=mod){
                shortt+=prices[i];
            }
            profit = max({nottake, take, shortt});
        } else if (s == 1) {
            long long nottake = solve(i + 1, prices, k, s);
            long long take =  solve(i + 1, prices, k - 1, 0);
            if(take!=mod){
                take+=prices[i];
            }
            profit = max({nottake, take});
        } else {
            long long nottake = solve(i + 1, prices, k, s);
            long long take = solve(i + 1, prices, k - 1, 0);
            if(take!=mod){
                take+=-prices[i];
            }
            profit = max({nottake, take});
        }

        return dp[i][k][s]= profit;
    }
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        bool buy = 1;
        int s = 0;
        memset(dp,-1,sizeof(dp));
        return solve(0, prices, k, s);
    }
};