class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<long long> maxi(n),maxi2(n);
        maxi[n - 1] = -1;
        maxi2[0]=-1;
        for (int i = n - 2; i >= 0; i--) {
            maxi[i] = max(maxi[i + 1], (long long)nums[i + 1]);
        }
        for(int i=1;i<n;i++){
            maxi2[i]=max(maxi2[i-1],(long long)nums[i-1]);
        }
        
        long long ans = 0;
        for (int i = 0; i < n-1; i++) {
            long long num1 = nums[i];
            if(maxi2[i]>num1){
                ans=max(ans,(maxi2[i]-num1)*maxi[i]);
            }
        }
        return ans;
    }
};