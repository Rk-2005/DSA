class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        int ans = 1;

        vector<int> dp(m, 1);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < i; j++) {
                bool ok = 1;

                for (int k = 0; k < n; k++) {
                    if (strs[k][i] < strs[k][j]) {
                        ok = false;
                        break;
                    }
                }

                if (ok) {
                    dp[i] = max(dp[i], dp[j] + 1);
                    ans = max(ans, dp[i]);
                }
            }
        }

        cout << ans << " ";

        return m - ans;
    }
};