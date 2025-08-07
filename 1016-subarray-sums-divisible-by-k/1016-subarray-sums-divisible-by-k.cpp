class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();

        int sum = 0;
        int ans = 0;
        map<int, int> mp;
        mp[0] = 1;
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            sum += (num);
            int rem = sum % k;
            if (rem < 0) {
                rem += k;
            }
            if (mp.find(rem) != mp.end()) {
                ans += mp[rem];
            }
            mp[rem]++;
        }
        return ans;
    }
};

// -1 2 5
// -1 1 6
// -1mod7 == 6 hoq