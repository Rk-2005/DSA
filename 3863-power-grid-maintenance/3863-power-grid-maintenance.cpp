class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int findParent(int node) {
        if (node == parent[node]) {
            return parent[node];
        }

        return parent[node] = findParent(parent[node]);
    }

    void unionn(int x, int y) {
        int p1 = findParent(x);
        int p2 = findParent(y);

        if (rank[p1] > rank[p2]) {
            rank[p1]++;
            parent[p2] = p1;
        } else {
            rank[p2]++;
            parent[p1] = p2;
        }
    }
    vector<int> processQueries(int c, vector<vector<int>>& connections,
                               vector<vector<int>>& queries) {
        parent.resize(c);
        rank.resize(c);
        for (int i = 0; i < c; i++) {
            parent[i] = i;
        }
        for (auto& it : connections) {
            int x = it[0];
            int y = it[1];
            x--;
            y--;
            unionn(x, y);
        }

        for (int i = 0; i < c; i++) {
            parent[i] = findParent(i);
        }

        map<int, set<int>> mp;

        for (int i = 0; i < c; i++) {
            int p = parent[i];
            mp[p].insert(i);
        }
        vector<int> ans;

        for (auto& it : queries) {
            int x = it[0];
            int y = it[1];

            y--;
            auto& st = mp[parent[y]];
            if (x == 2) {
                
                st.erase(y);
                
                cout<<endl;
                continue;
            }
            if (st.empty()) {
                ans.push_back(-1);
            } else {
                if (st.find(y) != st.end()) {
                    ans.push_back(y + 1);
                } else {
                    int no=*st.begin();
                    ans.push_back(no+1);
                }
            }
        }

        return ans;
    }
};

//  2,3,4 - >1
//  5,6 -> 7
// 1 2 3 4 5 6 7
// 1 1 1 1 7 7 1 [3,5]
// 1 1 1 1
// [2,6]