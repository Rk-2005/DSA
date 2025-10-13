class Solution {
public:
    bool solve(vector<int>& cur, int curcolor,
               unordered_map<int, vector<int>>& mp, int i) {

        cur[i] = curcolor;

        for (auto& it : mp[i]) {

            if (cur[it] == cur[i]) {
                return false;
            } else if (cur[it] == -1) {
                if (!solve(cur, 1 - curcolor, mp, it)) {
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {

        unordered_map<int, vector<int>> mp;

        int n = graph.size();

        for (int i = 0; i < n; i++) {
            auto it = graph[i];

            for (auto& j : it) {
                mp[i].push_back(j);
            }
        }

        int curcolor = 0;

        vector<int> cur(n, -1);

        for (int i = 0; i < n; i++) {
            if (cur[i] == -1) {
                if (solve(cur, curcolor, mp, i) == false)
                    return false;
            }
        }
        return 1;
    }
};

// 0 - 1

// 3   2

//
// 1->2
// ->3