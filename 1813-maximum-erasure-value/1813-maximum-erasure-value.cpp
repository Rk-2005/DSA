class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        int i = 0;
        int j = 0;
        int ans = 0;
        map<int, int> mp;
        int sm = 0;
        while (j < n) {
            int num = nums[j];
            mp[num]++;
            sm += num;
            while (i < n && mp[num] > 1) {
                mp[nums[i]]--;
                sm -= nums[i];
                i++;
            }
            ans = max(ans, sm);

            j++;
        }
        return ans;
    }
};