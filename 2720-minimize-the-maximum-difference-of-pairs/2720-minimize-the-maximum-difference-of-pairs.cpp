class Solution {
public:
    bool check(vector<int>& nums,int mid,int p){
        int n=nums.size();
        for(int i=1;i<n;i++){
            int dif=nums[i]-nums[i-1];
            if(dif<=mid){
                p--;
                i++;
            }
        }
        if(p<=0)return 1;

        return 0;
    }
    int minimizeMax(vector<int>& nums, int p) {
        int n = nums.size();
        sort(begin(nums),end(nums));
        int s=0;
        int e=nums[n-1]-nums[0];
        int ans=0;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(check(nums,mid,p)){
                ans=mid;
                e=mid-1;
            }else{
                s=mid+1;
            }
        }
        return ans;
    }
};