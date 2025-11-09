class Solution {
public:
    int N;
    int M;
    int dp[201][201][401];// 1e6
    int solve(vector<vector<int>>& grid, int i, int j, int k) {
        if (i < 0 || j < 0 || i >= N || j >= M || grid[i][j] == -1) {
            return INT_MIN;
        }

        if (i == N - 1 && j == M - 1) {
            cout<<k<<endl;
            if (k >= min(1,grid[N - 1][M - 1]))
                return grid[N-1][M-1];

            return INT_MIN;
        }

        if (dp[i][j][k] != -1) {
            return dp[i][j][k];
        }

        int num = grid[i][j];

        grid[i][j] = -1;

        
        int take = INT_MIN;

        if (k >= min(1,num)) {
            
            int a1 = solve(grid, i + 1, j, k - min(1,num));
            int a2 = solve(grid, i, j + 1, k - min(1,num));

            int t1 = num;

            int t2 = num;

            if (a1 == INT_MIN) {
                t1 = INT_MIN;
            } else {
                t1 += a1;
            }
            if (a2 == INT_MIN) {
                t2 = INT_MIN;
            } else {
                t2 += a2;
            }

            take = max(t1, t2);
        }

        grid[i][j] = num;

        return dp[i][j][k] = take;
    }
    int maxPathScore(vector<vector<int>>& grid, int k) {
        N = grid.size();
        M = grid[0].size();
        k=min(k,400);
        memset(dp, -1, sizeof(dp));
        int ans = solve(grid, 0, 0, k);

        return ((ans == INT_MIN) ? -1 : ans);
    }
};

// k =1
// 0 1
// 2 0

// 0 1 0
// 1 2 0
// 2 2 2

// k=1

// 0 1 
// 1 2 

// k=3
//  0 2 2
//  1 1 1
//  0 0 2