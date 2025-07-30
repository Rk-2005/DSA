class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=size(nums);
        int maxi=*max_element(nums.begin(),nums.end());
        int i=0;
        int c=0;
        int ans=0;
        while(i<n){
            int ele=nums[i];
            if(maxi==ele){
                c++;
            }else{
                c=0;
            }
            ans=max(ans,c);
            i++;
        }
        return ans;

    }
};