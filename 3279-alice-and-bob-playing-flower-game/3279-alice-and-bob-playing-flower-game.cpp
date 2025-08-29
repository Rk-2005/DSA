class Solution {
public:
    long long flowerGame(int n, int m) {
        long long ans = 0;

        long long odd = (n + 1) / 2;
        long long even = (n) / 2;

        ans += even * ((m + 1) / 2);

        ans += odd * ((m / 2));

        return ans;
    }
};

// two lanes of flower

// 3 2
// 1
// 2

// how much pairs will be there whose sum is odd

// even + odd =odd
