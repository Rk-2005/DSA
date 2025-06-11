class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int mini = prices[0];
        int ans = 0;
        for (int i = 1; i < n; i++) {
            mini = min(prices[i], mini);
            ans = max(ans, prices[i] - mini);
        }
        return ans;
    }
};