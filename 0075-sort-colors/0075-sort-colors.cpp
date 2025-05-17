class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        
        int c0=0,c1=0,c2=0;
        for(auto &it:nums){
            if(it==0)c0++;
            else if(it==1)c1++;
            else c2++;
        }
        int i=0;
        while(c0--){
            nums[i++]=0;
        }
        while(c1--){
            nums[i++]=1;
        }
        while(c2--){
            nums[i++]=2;
        }
    }
};