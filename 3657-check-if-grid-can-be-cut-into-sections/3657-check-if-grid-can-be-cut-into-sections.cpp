#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> find(int n, vector<vector<int>>& rec, bool isv) {
        vector<vector<int>> interval;
        for (int i = 0; i < n; i++) {
            if (isv) {
                interval.push_back({rec[i][0], rec[i][2]});
            } else {
                interval.push_back({rec[i][1], rec[i][3]});
            }
        }

        sort(interval.begin(), interval.end());
        vector<vector<int>> ans;

        // Merging intervals
        int prevst = interval[0][0];
        int prevend = interval[0][1];

        for (int i = 1; i < interval.size(); i++) {
            if (interval[i][0] < prevend) {
              
                prevend = max(prevend, interval[i][1]);
            } else {
               
                ans.push_back({prevst, prevend});
                prevst = interval[i][0];
                prevend = interval[i][1];
            }
        }

        // Push the last interval
        ans.push_back({prevst, prevend});
        return ans;
    }

    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>> ans = find(rectangles.size(), rectangles, true);
        if (ans.size() >= 3) return true;

        ans = find(rectangles.size(), rectangles, false);
        return ans.size() >= 3;
    }
};
