class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> temp = nums;

        sort(nums.rbegin(), nums.rend());

        map<int, int> mp;

        for (int i = 0; i < k; i++) {
            mp[nums[i]]++;
        }
        vector<int>ans;
        for (int i = 0; i < temp.size(); i++) {
            if (mp[temp[i]] != 0) {
                ans.push_back(temp[i]);
                mp[temp[i]]--;
            }
        }
        return ans;
    }
};