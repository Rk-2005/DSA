class Solution {
public:
    bool check(int mid, vector<int>& nums, int k, int i) {
        int n=nums.size();
        vector<int>dp(n+1,0);
        if(nums[0]<=mid){
            dp[0]=1;
        }
        if(nums[1]<=mid){
            dp[1]=1;
        }else{
            dp[1]=dp[0];
        }
        for(int i=2;i<n;i++){
            if(nums[i]<=mid){
                dp[i]=max(1+dp[i-2],dp[i-1]);
            }else
            dp[i]=dp[i-1];
        }
        
        return dp[n-1]>=k;
    }
    int minCapability(vector<int>& nums, int k) {
        int n = nums.size();
        if(n==1){
            return nums[0];
        }
        int s = 0;
        int e = *max_element(begin(nums), end(nums));
        int ans = 0;
        while (s <= e) {
            int mid = s + (e - s) / 2;
           
            if (check(mid, nums, k, 0)) {
                cout << mid << " ";
                ans = mid;
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return ans;
    }
};