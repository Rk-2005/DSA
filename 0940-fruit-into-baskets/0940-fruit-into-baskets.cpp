class Solution {
public:
    int totalFruit(vector<int>& nums) {
        int n = nums.size();

        int i = 0;
        int j = 0;
        map<int, int> mp;
        int ans = 0;
        while (j < n) {
            int num = nums[j];

            mp[num]++;

            while (i < n && mp.size() > 2) {
                mp[nums[i]]--;
                if (mp[nums[i]] == 0) {
                    mp.erase(nums[i]);
                }
                i++;
            }
            ans = max(ans, j - i + 1);
            j++;
        }
        return ans;
    }
};
// 0 1 0 2 0 2
// 0 0
// 1