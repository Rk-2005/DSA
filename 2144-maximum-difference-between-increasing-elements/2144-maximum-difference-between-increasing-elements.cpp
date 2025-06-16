class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        int ans = -1;
        int mini = nums[0];
        int maxi = nums[0];
        for (int i = 1; i < n; i++) {
            if (maxi<nums[i]){
                maxi=nums[i];
            }
            if(mini>nums[i]){
                mini=nums[i];
                maxi=-1;
            }
            ans=max(ans,maxi-mini);
        }
        return ans == 0 ? -1 : ans;
    }
};
// 2 9 1