#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

class Solution {
public:
    double soupServings(int n) {
        if (n > 4800) {
            return 1.0; // Empirically, probability approaches 1 for large n
        }

        n = (n + 24) / 25; // Scale down to reduce memory usage

        vector<vector<double>> dp(n + 1, vector<double>(n + 1, 0.0));
        dp[0][0] = 0.5; // Both empty at the same time
        for (int i = 1; i <= n; ++i) {
            dp[0][i] = 1.0; // A is empty before B
        }

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                dp[i][j] = 0.25 * (dp[max(0, i - 4)][j] +
                                    dp[max(0, i - 3)][max(0, j - 1)] +
                                    dp[max(0, i - 2)][max(0, j - 2)] +
                                    dp[max(0, i - 1)][max(0, j - 3)]);
            }
        }

        return dp[n][n];
    }
};




