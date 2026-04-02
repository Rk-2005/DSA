class Solution {
public:
    int numRows, numCols;

    long long dp[501][501][3];

    bool checkValid(int row, int col) {
        if (row < 0 || col < 0 || row >= numRows || col >= numCols) {
            return false;
        }
        return true;
    }
    
    vector<vector<int>> dir = {{0, 1}, {1, 0}};

    int findMaxAmount(vector<vector<int>>& coins, int row, int col, int k) {

        if (!checkValid(row, col)) {
            return INT_MIN;
        }

       
        if (row == numRows - 1 && col == numCols - 1) {

            if (k > 0 && coins[row][col] < 0) {
                return 0;
            }

            return coins[row][col];
        }

        if(dp[row][col][k]!=INT_MIN){
            return dp[row][col][k];
        }

        /* int[][][] dp = dp[numRows][numCols][2];
         dp[0][0][0] = coins[0][0];

         for ( int i = 1; i < numRows; i++){
             dp[i][0][0] = coins[i][0] + dp[i-1][0][0];
             if (coins[i][j] < 0) dp[i][0][1] = dp[i-1][0][0];
             else dp[i][0][1] = dp[i][0][0];
         }*/
        long long ans = INT_MIN;

        for (auto& d : dir) {
            int new_i = d[0] + row;
            int new_j = d[1] + col;

            if (coins[row][col] >= 0) {
                long long a =
                    coins[row][col] + findMaxAmount(coins, new_i, new_j, k);
                ans = max(ans, a);
            } else {
                if (k > 0) {
                    long long b = findMaxAmount(coins, new_i, new_j, k - 1);
                    ans = max(ans, b);
                }
                int next = findMaxAmount(coins, new_i, new_j, k);
                if (next != INT_MIN) {
                    long long c = coins[row][col] + next;
                    ans = max(ans, c);
                }
            }
        }

        return dp[row][col][k] =  ans;
    }

    int maximumAmount(vector<vector<int>>& coins) {
        numRows = coins.size();
        numCols = coins[0].size();

        for(int i=0;i<501;i++){
            for(int j=0;j<501;j++){
                for(int k=0;k<3;k++){
                    dp[i][j][k]=INT_MIN;
                }
            }
        }

        int k = 2;

        return findMaxAmount(coins, 0, 0, k);
    }
};

// dp[i][j][k]
