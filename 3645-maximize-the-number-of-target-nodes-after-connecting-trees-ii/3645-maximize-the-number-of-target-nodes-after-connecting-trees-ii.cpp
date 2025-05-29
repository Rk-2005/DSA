class Solution {
public:
    int solve(int node, unordered_map<int, vector<int>>& mp, vector<int>& vis,
              int len, vector<int>& duri) {
        vis[node] = 1;
        int ans = 0;
        duri[node] = len;
        for (auto& it : mp[node]) {
            if (vis[it])
                continue;
            if (len % 2 == 0) {
                ans += 1 + solve(it, mp, vis, len + 1, duri);
            } else {
                ans += solve(it, mp, vis, len + 1, duri);
            }
        }
        return ans;
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1,
                               vector<vector<int>>& edges2) {
        int n = edges1.size();
        int m = edges2.size();

        unordered_map<int, vector<int>> mp1, mp2;

        for (auto& it : edges1) {
            int x = it[0];
            int y = it[1];
            mp1[x].push_back(y);
            mp1[y].push_back(x);
        }
        for (auto& it : edges2) {
            int x = it[0];
            int y = it[1];
            mp2[x].push_back(y);
            mp2[y].push_back(x);
        }
        int maxi = 0;

        vector<int> vis(m + 1, 0);
        vector<int> duri(m + 1, 0);

        maxi = max(maxi, solve(0, mp2, vis, 0, duri));

        cout<<maxi<<" ";
        vector<int>durrri(m+1,0);
        for (int i=0;i<duri.size();i++) {
            int it=duri[i];
            if (it % 2 != 0) { 
                vector<int> vis1(m + 1, 0);
                maxi = max(maxi, solve(i, mp2, vis1, 0, durrri));
                break;
            }
        }
        cout<<maxi<<" ";
        vector<int> duri2(n + 1, 0);
        vector<int> vis2(n + 1, 0);
        int res = solve(0, mp1, vis2, 1, duri2);
        int res2 = 0;
        duri.resize(n+1,0);
        for (int i=0;i<duri2.size();i++) {
            
            int it=duri2[i];
            if (it % 2 == 0) {
                vector<int> vis3(n + 1, 0);
                res2 = solve(i, mp1, vis3, 1, duri);
                break;
            }
        }
        
        cout<<res<<" "<<res2<<" "<<endl;
        vector<int> ans(n + 1, 0);
        for(auto it:duri2){
            cout<<it<<" ";
        }
        for (int i = 0; i <= n; i++) {
            if (duri2[i] % 2 != 0) {
                ans[i] = res + 1 + maxi;
            } else {
                ans[i] = res2 + maxi + 1;
            }
        }
        return ans;
    }
};