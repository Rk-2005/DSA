class Solution {
public:
    int N;
    int solve(map<int, vector<int>>& mp, int node, int dest,
              map<pair<int, int>, vector<pair<int, int>>> &costs) {

        priority_queue<pair<int, int>,vector<pair<int, int>>,greater<pair<int, int>>> q;

        vector<int> visited(N, INT_MAX);

        q.push({0, 0});

        int ans = INT_MAX;

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                auto it = q.top();
                q.pop();

                int cur = it.first;
                int curcost = it.second;

                if (cur == dest) {
                   return curcost;
                }

                for (auto& child : mp[cur]) {

                    auto totaltime = costs[{cur, child}];
                    // vector<pair<int,int>>totaltime
                    
                    for(auto &pairr:totaltime){
                        int x=pairr.first;
                        int y=pairr.second;   
                        if(y<curcost){
                            continue;
                        }
                        int costy=max(curcost,x)+1;

                        if(visited[child]>costy){
                            visited[child]=costy;
                            q.push({child,costy});
                        }
                    }
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }

    int minTime(int n, vector<vector<int>>& edges) {
        map<int, vector<int>> mp;
        map<pair<int, int>, vector<pair<int, int>>> costs;
        N = n;
        for (auto it : edges) {
            int x = it[0];
            int y = it[1];
            int from = it[2];
            int to = it[3];

            if (costs.find({from, to}) == costs.end()) {
                mp[x].push_back(y);
            }

            costs[{x, y}].push_back({from, to});
        }

        return solve(mp, 0, n - 1, costs);
    }
};
