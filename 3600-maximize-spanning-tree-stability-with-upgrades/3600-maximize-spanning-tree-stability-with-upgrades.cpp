class Solution {
public:
    static bool cmp(vector<int>& a1, vector<int>& a2) {

        int a = a1[2];
        int b = a2[2];

        return b < a;
    }
    vector<int> parent;
    vector<int> rank;

    int findParent(int x) {
        if (parent[x] == x) {
            return x;
        }

        return parent[x] = findParent(parent[x]);
    }

    void Union(int x, int y) {
        int x_p = findParent(x);
        int y_p = findParent(y);

        if (rank[x_p] > rank[y_p]) {
            parent[y_p] = x_p;
        } else if (rank[x_p] < rank[y_p]) {
            parent[x_p] = y_p;
        } else {
            parent[y_p] = x_p;
            rank[x_p]++;
        }
    }
    int N;
    bool check(vector<vector<int>>& edges, int mid, int k) {

        iota(parent.begin(), parent.end(), 0);
        fill(rank.begin(), rank.end(), 0);

        for (auto& it : edges) {
            int x = it[0];
            int y = it[1];
            int z = it[2];
            int m = it[3];

            if (m == 1) {
                int x_p = findParent(x);
                int y_p = findParent(y);

                if (x_p == y_p) {
                    return false;
                }

                Union(x, y);
            }
        }

        for (auto& it : edges) {
            int x = it[0];
            int y = it[1];

            int p_x = findParent(x);
            int p_y = findParent(y);

            if (p_x == p_y) {
                continue;
            }

            if (it[3] == 1)
                continue;

            if (it[2] < mid) {
                if (k == 0)
                    continue;

                if (it[2] * 2 >= (mid)) {
                    Union(x, y);
                }

                k--;
            } else {
                Union(x, y);
            }
        }

        unordered_set<int> st;

        for (int i = 0; i < parent.size(); i++) {
            int p = findParent(i);

            st.insert(p);
        }
        return st.size() == 1;
    }

    int maxStability(int n, vector<vector<int>>& edges, int k) {
        N = n;

        int sz = edges.size();

        int s = 0;

        int e = 1e9;

        parent.resize(n);
        rank.resize(n);

        iota(parent.begin(), parent.end(), 0);

        for (auto& it : edges) {
            int x = it[0];
            int y = it[1];
            int z = it[2];
            int m = it[3];

            if (m == 1)
                e = min(e, z);
        }

        sort(edges.begin(), edges.end(), cmp);

        
        for(auto it:edges){
            cout<<it[2]<<endl;
        }

        int ans = -1;
        while (s <= e) {

            int mid = s + (e - s) / 2;

            if (check(edges, mid, k)) {
                ans = mid;
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }
        return ans;
    }
};

// 0 1 2
// 