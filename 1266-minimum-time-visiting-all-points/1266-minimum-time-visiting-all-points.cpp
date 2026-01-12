class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n = points.size();

        int ans = 0;

        for (int i = 1; i < n; i++) {
            int x1 = points[i-1][0];
            int x2 = points[i][0];
            int y1 = points[i-1][1];
            int y2 = points[i][1];

            int dx = abs(x2-x1);
            int dy=  abs(y2-y1);

            ans+=min(dy,dx)+abs(dy-dx);
        }
        
        return ans;
    }
};

// [1,1] , [3,4]

/// [4+9 = 13]
// 32 - (5)

// sqrt(13) + sqrt()
// [3,4] [-1,0]
// 