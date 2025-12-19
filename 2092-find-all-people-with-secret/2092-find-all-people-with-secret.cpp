class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings,
                              int firstPerson) {

        int m = meetings.size();

        unordered_map<int, vector<pair<int, int>>> mp;

        for (auto &it : meetings) {
            int x = it[0];
            int y = it[1];
            int t = it[2];

            mp[x].push_back({y, t});
            mp[y].push_back({x, t});
        }

        vector<int> vis(n, INT_MAX);

        vis[0] = 0;
        vis[firstPerson] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        pq.push({0, 0});
        pq.push({0, firstPerson});
        vector<bool>dekhahua(n,0);
        while (!pq.empty()) {

            auto it = pq.top();
            pq.pop();

            int time = it.first;
            int node = it.second;
            
            if(dekhahua[node]){
                continue;
            }
            dekhahua[node]=1;

            for (auto &child : mp[node]) {

                int node2 = child.first;

                int t = child.second;

                if (t >= time && vis[node2] > t) {
                    pq.push({t, node2});
                    vis[node2] = t;
                }
            }
        }

        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if (vis[i] != INT_MAX) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};

// if suppose times are distinct
// then its very easy que
// just we have to sort array then check in set if element is present

// [1,2,3],[2,3,3]

// ( 1 <-> 2 <-> 3 ) // if that value has secret i will push that into queue
// then i will traverse and mark childs also

// 1 - (2,2),(5,40)
// 2 - > (5,3)

// (2,2),(5,40),(5,3)