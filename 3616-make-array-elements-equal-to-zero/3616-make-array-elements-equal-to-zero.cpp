class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n=size(nums);
        vector<int>prefix(n);
        vector<int>suffix(n);
        prefix[0]=nums[0];
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+nums[i];
        }
        suffix[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            suffix[i]=suffix[i+1]+nums[i];
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                if(prefix[i]==suffix[i]){
                    ans+=2;
                }else if(abs(prefix[i]-suffix[i])==1){
                    ans+=1;
                }
            }
        }
        return ans;
    }
};