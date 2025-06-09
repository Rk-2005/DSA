class Solution {
public:
    const int mod = 1e9 + 7;
    
    long long factorial(int n) {
        long long result = 1;
        for (int i = 2; i <= n; ++i) {
            result = (result * i) % mod;
        }
        return result % mod;
    }

    int countPermutations(vector<int>& complexity) {
        long long n = complexity.size();
        for (int i = 1; i < n; i++) {
            if (complexity[i] <= complexity[0])
                return 0;
        }
        n--;
        long long ans = (factorial(n)) % mod;
        return ans;
    }
};

// 0