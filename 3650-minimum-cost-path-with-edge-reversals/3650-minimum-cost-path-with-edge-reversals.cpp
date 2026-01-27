class Solution {
public:
    int findans(unordered_map<int, vector<pair<int, int>>>& mp, int n) {
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        pq.push({0, 0});
        vector<int> res(n, INT_MAX);
        res[0] = 0;
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int node = it.second;

            int curcost = it.first;
            if (node == n - 1) {
                return curcost;
            }
            for (auto& it2 : mp[node]) {
                int node1 = it2.first;
                int cost = it2.second;
                if (cost + curcost < res[node1]) {

                    res[node1] = cost + curcost;
                    pq.push({res[node1], node1});
                }
            }
        }
        return -1;
    }
    int minCost(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<pair<int, int>>> mp;

        for (auto& it : edges) {
            int x = it[0];
            int y = it[1];
            int c = it[2];
            {
                mp[x].push_back({y, c});
            }

            mp[y].push_back({x, 2 * c});
        }

        return findans(mp, n);
    }
};