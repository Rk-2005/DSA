class Solution {
public:
    vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1},{-1,0}};

    bool dfs(vector<vector<int>>& grid, int i, int j) {

        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() ||
            grid[i][j] == 1) {
            return false;
        }

        if (i == grid.size() - 1) {
            return true;
        }

        grid[i][j] = 1;

        for (auto& it : dir) {
            int new_i = it[0] + i;
            int new_j = it[1] + j;

            if (dfs(grid, new_i, new_j)) {
                return true;
            }
        }

        return false;
    }

    bool check(int mid, vector<vector<int>>& cells, int row, int col) {

        vector<vector<int>> grid(row, vector<int>(col));

        for (int i = 0; i <= mid; i++) {
            auto cell = cells[i];
            int x = cell[0];
            int y = cell[1];

            x--;
            y--;

            grid[x][y] = 1;
        }

        for (int i = 0; i < grid[0].size(); i++) {
            if (grid[0][i]==0 && dfs(grid, 0, i)) {
                return true;
            }
        }
        return false;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {

        int s = 0;
        int e = cells.size()-1;
        int ans = 0;
        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (check(mid, cells, row, col)) {
                ans = mid;
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }
        return ans + 1;
    }
};