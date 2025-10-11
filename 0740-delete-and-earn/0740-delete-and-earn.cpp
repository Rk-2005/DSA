class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        map<int, int> mp;

        for (auto& it : nums) {
            mp[it]++;
        }

        vector<int> dp(n, 0);
        dp[0] = nums[0];
        for (int i = 1; i < n; i++) {

            dp[i] = nums[i] * mp[nums[i]];

            int idx = (upper_bound(nums.begin(), nums.begin() + i, nums[i] - 2) -
                      nums.begin()) - 1;
           
            if (idx >= 0) {
                dp[i] = max(dp[i], (nums[i]) * mp[nums[i]] + (dp[idx]));
            }
            dp[i] = max(dp[i], dp[i - 1]);

            cout << dp[i] << " ";
        }

        return dp[n - 1];
    }
};

// nums[i] -  > nums[i]-1 and nums[i]+1
// 2 3     4
// 2 3+(_) 4+(dp[2])
//

// 2 2 3 4