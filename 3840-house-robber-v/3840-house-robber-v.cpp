class Solution {
public:
    long long rob(vector<int>& nums, vector<int>& colors) {

        int n = nums.size();

        vector<long long> ans(n);

        ans[0] = nums[0];

        for (int i = 1; i < n; i++) {
            long long nottake = ans[i - 1];

            long long take = nums[i];

            if (colors[i] != colors[i - 1]) {
                take = nums[i] + ans[i - 1];
            } else if (i >= 2) {
                take = nums[i] + ans[i - 2];
            }

            ans[i] = max(take, nottake);
        }
        return ans[n - 1];
    }
};

// 10 1 3 9
// 10   13

// 