class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {

        vector<vector<int>> Matrix(n, vector<int>(n));

        for (auto& it : queries) {
            int x1 = it[0];
            int y1 = it[1];
            int x2 = it[2];
            int y2 = it[3];

            Matrix[x1][y1] += 1;
            if(x2+1<n && y2+1<n)
            Matrix[x2 + 1][y2 + 1] += 1;
            if(x2+1<n)
            Matrix[x2+1][y1] += -1;
            if(y2+1<n)
            Matrix[x1][y2 + 1] += -1;
        }

        for(int i=0;i<n;i++){
            for(int j=1;j<n;j++){
                Matrix[i][j]+=Matrix[i][j-1];
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=1;j<n;j++){
                Matrix[j][i]+=Matrix[j-1][i];
            }
        }

        return Matrix;
    }
};

// [0,0,1,1,]

// [1,0,2,0]

// [0,0,2,2]

// [0,0,2,1]

//  1 1 - 0
//  0 0 0 0
//  0 0 0 0
// -1 -1 0 0

// [0,1,2,3]
/* 0 1 2 3 4
0[0,1,0,0,0],
1[0,0,0,0,0],
2[0,0,0,0,0],
3[0,-1,0,0,1]]
4[0,0,0,0,0]

 */
