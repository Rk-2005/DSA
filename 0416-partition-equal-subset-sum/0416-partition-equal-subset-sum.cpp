class Solution {
public:
    int dp[201][20000];
    bool solve(vector<int>& nums,int &sum,int n,int i,int cursum){
        if(cursum==(sum-cursum)){
            return true;
        }
        if(i>=n)return 0;

        if(dp[i][cursum]!=-1)return dp[i][cursum];
        bool take=false;
        if(cursum<(sum-cursum)){
            take=solve(nums,(sum),n,i+1,cursum+nums[i]);
        }
        
        bool nottake=solve(nums,sum,n,i+1,cursum);

        if(take== true || nottake){
            return dp[i][cursum]= 1;
        }
        return  dp[i][cursum]=0;
    }    
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        memset(dp,-1,sizeof(dp));
        sort(begin(nums),end(nums));
        int sum=accumulate(begin(nums),end(nums),0);
        int cursum=0;
        return solve(nums,sum,n,0,0);
    }
};
//1 5 5 11 == 22 
// x1+x2=sum

// x1=sum-x2