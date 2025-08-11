class Solution {
public:
    void solve(vector<int>& nums,int target, vector<vector<int>>&ans,int i,int j){

        while(i<j){
            int sum=nums[i]+nums[j];
          
            if(sum>target){
                j--;
            }else if(sum<target){
                i++;
            }else{
                ans.push_back({-(target),nums[i],nums[j]});
                while(i<nums.size()-1 && nums[i]==nums[i+1]){
                    i++;
                }
                while(j>0 && nums[j]==nums[j-1]){
                    j--;
                }
                 i++;
                 j--;
            }
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = size(nums);
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
             if(i>0&&nums[i]==nums[i-1])continue;
            int target =-(nums[i]);

            solve(nums,target,ans,i+1,n-1);
            
        }
        return ans;
    }
};
// set a single element as my target (a+b+c=0; b+c=-a)
// then i will apply 2-pointer on rest of nums[i]
// but there is one problem
// when there are duplicates element
//[-4,-1,-1,0,1,2,2]