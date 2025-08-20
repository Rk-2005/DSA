class Solution {
public:
    long long minArraySum(vector<int>& nums, int k) {
        long long n = nums.size();

        vector<long long> dp(n, 0), prefix(n, 0);

        prefix[0] = nums[0];

        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + nums[i];
        }
        
//        cout << endl;

        map<long long, long long> mp;

        mp[0] = -1;

        long long sum = 0;

        for (int i = 0; i < n; i++) {
            sum += nums[i];

            long long rem = sum % k;

            long long nottake = (i > 0 ? dp[i - 1] : 0);
            long long take = 0;
            // cout<<" rem "<<rem<<" ";
            if (mp.find(rem) != mp.end()) {
                if (mp[rem] == -1) {
                    take = sum;
                } else {

                    take = (sum - prefix[mp[rem]]) + dp[mp[rem]];
                }
            }

            dp[i] = max(take, nottake);
            
            mp[rem] = i;
        }

        return prefix[n - 1] - dp[n - 1];
    }
};

//
//   1 2 3 4 5
//   3 4 8 9 14 // prefix
//   3 1 4 1 5 = 14 (6+3) =9
//   0 1 2 0  // map
//   3 3 3 14 // dp