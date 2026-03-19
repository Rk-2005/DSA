class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int RowSize = grid.size();
        int ColSize = grid[0].size();

        vector<vector<int>> temp(RowSize, vector < int >(ColSize, 0));
        vector<vector<int>> temp2(RowSize, vector < int > (ColSize, 0));

        for (int i = 0; i < RowSize; i++) {
            for (int j = 0; j < ColSize; j++) {
                if (grid[i][j] == 'X') {
                    temp[i][j] = 1;
                    temp2[i][j] = 1;
                } else if (grid[i][j] == 'Y') {
                    temp[i][j] = -1;
                }
            }
        }

        for (int i = 0; i < RowSize; i++) {
            for (int j = 1; j < ColSize; j++) {
                temp[i][j] += temp[i][j - 1];
                temp2[i][j] += temp2[i][j - 1];
            }
        }

        for (int j = 0; j < ColSize; j++) {
            for (int i = 1; i < RowSize; i++) {
                temp[i][j] += temp[i - 1][j];
                temp2[i][j] += temp2[i-1][j];
            }
        }

        int ans = 0;

        for (int i = 0; i < RowSize; i++) {
            for (int j = 0; j < ColSize; j++) {
                if (temp[i][j]==0 && temp2[i][j]>=1) {
                    ans++;
                }
            }
        }

        return ans;
    }
};

// X y .
// equal freq of x and y
// 1 0
// 0 -1
//

//