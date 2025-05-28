class Solution {
public:
    int findMax(unordered_map<int, vector<int>>& tree, int node, int k,
                vector<int>& vis) {
        if (k <=0) {
            return 0;
        }
        vis[node] = 1;
        int ans = 0;
        for (auto& it : tree[node]) {
            if (vis[it])
                continue;
            ans += 1 + findMax(tree, it, k - 1, vis);
        }
        return ans;
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1,
                               vector<vector<int>>& edges2, int k) {
        int n = edges1.size();
        int m = edges2.size();
        unordered_map<int, vector<int>> tree1, tree2;

        for (auto& it : edges1) {

            tree1[it[0]].push_back(it[1]);
            tree1[it[1]].push_back(it[0]);
        }

        for (auto& it : edges2) {
            tree2[it[0]].push_back(it[1]);
            tree2[it[1]].push_back(it[0]);
        }
        int maxi = 0;
        for (int i = 0; i <= m; i++) {
            vector<int> vis1(m + 1, 0);
            maxi = max(maxi, findMax(tree2, i, k - 1, vis1));
        }
        if (k != 0) {
            maxi++;
        }
        vector<int> ans;
        for (int i = 0; i <= n; i++) {
            vector<int> vis2(n + 1, 0);
            int res = findMax(tree1, i, k, vis2)+maxi+1;
            ans.push_back(res);
        }
        cout << maxi << " ";
        return ans;
    }
};

// 1 thing is clear i will choose node from tree 2 which has highest degree
//