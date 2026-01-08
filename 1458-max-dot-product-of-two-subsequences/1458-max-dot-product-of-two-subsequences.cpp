class Solution {
public:
    int dp[501][501];
    int solve(int n, int m, vector<int>& nums1, vector<int>& nums2, int i,
              int j) {

        if (i < 0 || j < 0 || i >= n || j >= m) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int take = 0;

        int a = solve(n, m, nums1, nums2, i + 1, j + 1);

        if (a == INT_MIN) {
            a = 0;
        }

        take = (nums1[i] * nums2[j]) + a;

        int nottake = max(solve(n, m, nums1, nums2, i + 1, j),
                          solve(n, m, nums1, nums2, i, j + 1));

        return dp[i][j] = max(take, nottake);
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        memset(dp, -1, sizeof(dp));
        int ans = solve(n, m, nums1, nums2, 0, 0);
        if (ans == 0) {
            int c0 = count(nums1.begin(), nums1.end(), 0);
            int c01 = count(nums2.begin(), nums2.end(), 0);

            if (c0 > 0 || c01 > 0) {
                return 0;
            } else {
                sort(nums1.begin(), nums1.end());
                sort(nums2.begin(), nums2.end());
                int a = nums1[0];
                int b = nums2[0];
                int c = nums1[n - 1];
                int d = nums2[m - 1];
                int maxi = max({a * d, a * b, b * c, c * d});
                return maxi;
            }
        }
        return ans;
    }
};
// [2,1,-2,5] , [3,0,-6]

//   0 1
//  [2,3]
//  [1,2]