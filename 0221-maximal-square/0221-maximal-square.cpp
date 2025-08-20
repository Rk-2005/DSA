class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n=size(matrix);
        int m=size(matrix[0]);
        vector<vector<int>>dp(n,vector<int>(m,0));
        int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || j==0 ){
                    dp[i][j]=matrix[i][j]-'0';
                }else{
                    if(matrix[i][j]!='0')
                    dp[i][j]=1+min({dp[i][j-1],dp[i-1][j] ,dp[i-1][j-1]});
                }
                maxi=max(maxi,dp[i][j]);
               
            }
        }
        return maxi*maxi;
    }
};