class Solution {
public:
    int FindMinAbsDif(int& r, int& c, int& k, vector<vector<int>>& grid) {
        int mini = INT_MAX;

        set<int> st;

        for (int i = r; i < r + k; i++) {
            for (int j = c; j < c + k; j++) {
                st.insert(grid[i][j]);
            }
        }

        if (st.size() == 1) {
            return 0;
        }

        int prev = *st.begin();

        for (auto it : st) {
            if (it == prev) {
                continue;
            }
            mini = min(mini, abs(it - prev));
            prev = it;
        }
        return mini;
    }
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int row = grid.size();
        int col = grid[0].size();

        vector<vector<int>> result(row - k + 1, vector<int>(col - k + 1));

        for (int r = 0; r <= row - k; r++) {
            for (int c = 0; c <= col - k; c++) {
                result[r][c] = FindMinAbsDif(r, c, k, grid);
            }
        }
        return result;
    }
};