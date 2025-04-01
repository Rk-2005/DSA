class Solution {
public:
typedef long long ll;
     ll dp[100001];
     
    ll solve(vector<vector<int>>& questions, int i) {
        if (i >= questions.size()) {
            return 0;
        }
        if(dp[i]!=-1)return dp[i];
        ll nottake = solve(questions, i + 1);
        ll take = 0;

        take = questions[i][0] + solve(questions, i + questions[i][1]+1);

        return dp[i]=max(take, nottake);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        ll n = questions.size();
        memset(dp,-1,sizeof(dp));
        return solve(questions, 0);
    }
};
// 3
// 4