class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        for(auto &it:nums){
            if(it==0){
                it=-1;
            }
        }
        unordered_map<int,int>mp;
        int sum=0;
        int ans=0;
        mp[0]=-1;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(mp.find(sum)!=mp.end()){
                ans=max(ans,(i-mp[sum]));
            }else{
                mp[sum]=i;
            }
        }
        return ans;
    }
};

// -1 1 1 1 1 1 -1 -1
// -1 0 1 2 3 4  3 2 


// 
//+e+f=4
// a+b+c+d+e+f+h=3
// -1 1 -1
// -1 0