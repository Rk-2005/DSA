class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n=nums.size();
        long long len=1;
        long long sum=0;
        long long i=0;
        long long j=0;
        long long ans=0;
        while(j<n){
            long long num=nums[j];
            sum+=num;
            
            if((sum*len)<k){
                ans+=j-i+1;
            }else{
                while(i<=j && ((sum)*len)>=k){
                    sum-=nums[i];
                    len--;
                    i++;
                }
                ans+=j-i+1;
                
            }
            len++;
            j++;
        }
        return ans;
    }
};
// 2 1 4 3 5
// 2 , 3 , 