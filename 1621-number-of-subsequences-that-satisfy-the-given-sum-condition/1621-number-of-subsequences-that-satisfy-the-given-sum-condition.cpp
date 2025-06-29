class Solution {
public:
    // 1 2
   const long long mod = 1e9 + 7;

long long modpow(long long b) {
    long long res = 1;
    long long base = 2;

    while (b > 0) {
        if (b % 2 == 1) {
            res = (res * base) % mod;
        }
        base = (base * base) % mod;
        b /= 2;
    }

    return res;
}

    int numSubseq(vector<int>& nums, int target) {
        long long n = nums.size();
        sort(nums.begin(), nums.end());
    

        long long i = 0;
        long long j = n - 1;
        long long ans = 0;
        while (i <= j) {
            long long num = nums[i] % mod + nums[j] % mod;
            
            if (num <= target) {
               ans = (ans + modpow(j - i)) % mod;
              i++;
            } else {
                j--;
            }
        }
        return ans;
    }
};
// i   j
// 3 5 6 7
// 3
// 3 5
// 3 6
// 3 5 6
// 1 2 3 4
// 0 1 2 3 // 2^(n)
// 1 ,
// [1,2], [1,3],[1,4]
// [1,2,3],[1,2,4],[1,3,4]
//  [1,2,3,4]
// 2^

// 2^3 = 8
// 2*2*2