class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();

        vector<long long> prefix(n, 0);
        vector<long long> prefixSum(n, 0);
        prefixSum[0] = prices[0] * strategy[0];

        prefix[0] = prices[0];

        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + prices[i];
        }
        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i - 1] + (prices[i] * strategy[i]);
        }

        long long curans = 0;

        for (int i = 0; i < n; i++) {
            curans += (strategy[i] * prices[i]);
        }
   
       
        long long res = curans;

        res = max(curans, curans - (prefixSum[k - 1]) +
                              (prefix[k - 1] - prefix[(k / 2) - 1]));

        for (int i = k; i < n; i++) {
            long long tosub = prefixSum[i] - prefixSum[i - k];
            long long toadd = prefix[i] - (prefix[i - (k / 2)]);

            res = max(res, curans - tosub + toadd);
        }
        return res;
    }
};

// -1 0 1 = 4
//  1 2 3 4 5 6
//  1 1 1 0 -1 -1

//