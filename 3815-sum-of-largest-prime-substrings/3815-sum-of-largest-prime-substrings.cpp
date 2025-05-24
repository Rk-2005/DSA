class Solution {
public:
    bool isPrime(long long num) {
        if (num == 1) {
            return 0;
        }

        for (int i = 2; i <= sqrt(num); i++) {
            if (num % i == 0) {
                return 0;
            }
        }
        return 1;
    }

    long long sumOfLargestPrimes(string s) {
        long long n = s.size();
        vector<long long> primes;
        for (int i = 0; i < n; i++) {
            string t = "";
            for (int j = i; j < n; j++) {
                t += s[j];
                long long no = stoll(t);
                // cout << no << " ";
                if (isPrime(no) == true) {
                    primes.push_back(no);
                }
            }
        }
        unordered_set<long long> p(begin(primes), end(primes));
        vector<long long> ans;
        for (auto& it : p) {
            ans.push_back(it);
        }
        long long res = 0;
        sort(ans.rbegin(), ans.rend());
        long long b=ans.size();
        long long z=3;
        for (int i = 0; i < min(z, b); i++) {
            res += ans[i];
        }
        return res;
    }
};