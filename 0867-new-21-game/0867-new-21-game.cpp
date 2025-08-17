class Solution {
public:


double new21Game(int n, int k, int maxPts) {
    // Edge case: If k is 0, Alice starts with k points, so if n >= 0, she wins with probability 1.
    if (k == 0) {
        return 1.0;
    }

    // Edge case: If n >= k + maxPts - 1, Alice can always reach n or less points.
    if (n >= k + maxPts - 1) {
        return 1.0;
    }

    // dp[i] represents the probability of having exactly i points.
    vector<double> dp(n + 1, 0.0);
    dp[0] = 1.0; // Base case: Alice starts with 0 points.

    double sum = 1.0; // Sum of dp[i] for i in [i-maxPts, i-1]
    double probability = 0.0;

    for (int i = 1; i <= n; ++i) {
        dp[i] = sum / maxPts;

        if (i < k) {
            sum += dp[i];
        } else {
            probability += dp[i]; // Accumulate probability if i >= k and i <= n
        }

        if (i >= maxPts) {
            sum -= dp[i - maxPts];
        }
    }

    return probability;
}

};