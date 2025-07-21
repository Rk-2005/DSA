class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = 9;  // Since the Sudoku board is 9x9
        // Check rows
        for(int i = 0; i < n; i++) {
            unordered_map<int, int> mp;
            for(int j = 0; j < n; j++) {
                if(board[i][j] == '.') continue;
                int num = board[i][j] - '0';
                if(num < 1 || num > 9 || ++mp[num] > 1) {
                    return false;
                }
            }
        }
        
        // Check columns
        for(int i = 0; i < n; i++) {
            unordered_map<int, int> mp;
            for(int j = 0; j < n; j++) {
                if(board[j][i] == '.') continue;
                int num = board[j][i] - '0';
                if(num < 1 || num > 9 || ++mp[num] > 1) {
                    return false;
                }
            }
        }
        
        // Check 3x3 subgrids
        for(int row = 0; row < n; row += 3) {
            for(int col = 0; col < n; col += 3) {
                unordered_map<int, int> mp;
                for(int i = row; i < row + 3; i++) {
                    for(int j = col; j < col + 3; j++) {
                        if(board[i][j] == '.') continue;
                        int num = board[i][j] - '0';
                        if(num < 1 || num > 9 || ++mp[num] > 1) {
                            return false;
                        }
                    }
                }
            }
        }
        
        return true;
    }
};
