class Solution {
public:
    void solve(vector<int>& edges, int node, vector<int>& fill, int st) {
        while (node != -1 && fill[node] == -1) {
            fill[node] = st;
            st++;
            node = edges[node];
        }
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        
        vector<int> fill(n, -1);   // Distance from node1
        vector<int> fill2(n, -1);  // Distance from node2
        
        solve(edges, node1, fill, 0);
        solve(edges, node2, fill2, 0);

        int ans = INT_MAX;
        int idx = -1;

        for (int i = 0; i < n; i++) {
            if (fill[i] != -1 && fill2[i] != -1) {
                int maxDist = max(fill[i], fill2[i]);
                if (maxDist < ans) {
                    ans = maxDist;
                    idx = i;
                }
            }
        }
        return idx;
    }
};
