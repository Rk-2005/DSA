class Solution {
public:
    void dfs(unordered_map<int, vector<int>>& mp, int &node,
            vector<bool>& visited) {

        visited[node] = 1;
        for (auto it : mp[node]) {
            if(visited[it])continue;
            dfs(mp, it, visited);
        }
    }

    int FindComponets(unordered_map<int, vector<int>>& mp, int &n) {

        int ans = 0;
        vector<bool> vis(n);
        for (int i = 0; i < n; i++) {
            if (vis[i])
                continue;
            
            dfs(mp, i, vis);
            ans++;
        }
        return ans;
    }
    int minTime(int n, vector<vector<int>>& edges, int k) {
       
        int a=0;
        for(auto it:edges){
            a=max(a,it[2]);
        }
        int s = 0;
        int e = a+1;
        int ans = 0;
        while (s <= e) {
            int mid = s + (e - s) / 2;

            unordered_map<int, vector<int>> mp;

            for (auto& it : edges) {
                int x = it[0];
                int y = it[1];
                int z = it[2];
                if (z > mid) {
                    mp[x].push_back(y);
                    mp[y].push_back(x);
                }
            }
            int componets = FindComponets(mp, n);
          //  cout<<componets<<" ";
            if (componets >=k) {
                ans = mid;
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return ans;
    }
};

// if no of component < = k return 0;

// 0