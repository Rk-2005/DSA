class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies,
                   vector<vector<int>>& keys,
                   vector<vector<int>>& containedBoxes,
                   vector<int>& initialBoxes) {

        int n = status.size();

        unordered_map<int, vector<int>> boxes, keyss;

        for (int i = 0; i < n; i++) {
            for (auto& it : containedBoxes[i]) {
                boxes[i].push_back(it);
            }
        }
        for (int i = 0; i < n; i++) {
            for (auto& it : keys[i]) {
                keyss[i].push_back(it);
            }
        }
        queue<int> q;
        set<int> temp;
        set<int> vis;
        for (auto& it : initialBoxes) {
            if (status[it] == 1) {
                vis.insert(it);
                q.push(it);
            } else
                temp.insert(it);
        }
        if (q.empty()) {
            return 0;
        }
        long long ans = 0;

        while (!q.empty()) {
            auto it = q.front();
            q.pop();

            ans += candies[it];

            for (auto& child : boxes[it]) {
                if (vis.find(child) != vis.end())
                    continue;
                if (status[child] == 1) {
                    vis.insert(child);
                    q.push(child);
                } else {
                    temp.insert(child);
                }
            }

            for (auto& key : keys[it]) {
                if (temp.find(key) != temp.end() &&
                    vis.find(key) == vis.end()) {
                    vis.insert(key);
                    q.push(key);
                }
                status[key] = 1;
            }
        }
        return ans;
    }
};