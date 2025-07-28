class Solution {
public:
    long long numOfSubsequences(string s) {
        int n = s.size();

        vector<long long> CountL(n), CountT(n);

        for (int i = 0; i < n; i++) {
            if (s[i] == 'L') {
                CountL[i]++;
            }
            if (s[i] == 'T') {
                CountT[i]++;
            }
        }
        for (int i = 1; i < n; i++) {
            CountL[i] += CountL[i - 1];
        }
        for (int i = n - 2; i >= 0; i--) {
            CountT[i] += CountT[i + 1];
        }
       
        long long ans1 = 0;
        long long  ans2 = 0;
        long long ans3 = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == 'C') {
                ans1 += ((CountL[i] + 1) * (CountT[i]));
                ans2 += ((CountL[i]) * (CountT[i] + 1));
                ans3 += ((CountL[i]) * (CountT[i]));
            }
        }
        long long b=0;
        for (int i = 0; i < n; i++) {
            long long res = (long long)(CountL[i]) * (long long)(CountT[i]);
            b = max(b,res);
        }
        return max({ans1, ans2, ans3+b});
    }
};
// LLT