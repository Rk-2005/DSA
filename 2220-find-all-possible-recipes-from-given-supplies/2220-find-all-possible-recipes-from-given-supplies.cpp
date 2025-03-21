class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes,
                                  vector<vector<string>>& ingredients,
                                  vector<string>& supplies) {
        int n = recipes.size();
        unordered_map<string, vector<int>> mp;
        unordered_set<string> st(begin(supplies), end(supplies));
        vector<int> indegre(n, 0);
        for (int i = 0; i < n; i++) {
            for (auto& it : ingredients[i]) {
                if (st.find(it) == st.end()) {
                    mp[it].push_back(i);
                    indegre[i]++;
                }
            }
        }
        queue<int> q;
        for (int i = 0; i < indegre.size(); i++) {
            if (indegre[i] == 0) {
                q.push(i);
            }
        }
        vector<string> res;
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            res.push_back(recipes[it]);
            for (auto it : mp[recipes[it]]) {
                indegre[it]--;
                if (indegre[it] == 0) {
                    q.push(it);
                }
            }
        }

        return res;
    }
};