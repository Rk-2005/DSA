class Solution {
public:
    int n, m;
    vector<vector<int>> directions = {{1, -1}, {1, 0}, {1, 1}};
    int dp[71][71][71];  // For memoization: row, c1, c2
    
    int solve(vector<vector<int>>& grid, int row, int c1, int c2) {
        // Base cases
        if (c1 < 0 || c2 < 0 || c1 >= m || c2 >= m) return -1e9;  // Invalid columns
        if (row == n) return 0;  // Reached beyond the last row
        
        // Check memoization
        if (dp[row][c1][c2] != -1) return dp[row][c1][c2];
        
        // Pick cherries from the current row
        int cherry = grid[row][c1];
        if (c1 != c2) cherry += grid[row][c2];
        
        // Recursively calculate the maximum cherries for the next row
        int ans = 0;
        for (auto& dir1 : directions) {
            for (auto& dir2 : directions) {
                int new_c1 = c1 + dir1[1];
                int new_c2 = c2 + dir2[1];
                ans = max(ans, solve(grid, row + 1, new_c1, new_c2));
            }
        }
        
        // Store the result in dp and return
        return dp[row][c1][c2] = cherry + ans;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        
        // Initialize dp with -1
        memset(dp, -1, sizeof(dp));
        
        // Start the two robots at (0, 0) and (0, m-1)
        return solve(grid, 0, 0, m - 1);
    }
};
