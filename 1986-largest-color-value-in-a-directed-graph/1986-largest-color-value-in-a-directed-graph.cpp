class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        queue<int> q;
        vector<int> indegree(n, 0);
        unordered_map<int, vector<int>> mp;
        for (auto& it : edges) {
            mp[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }
        vector<vector<int>> dp(n, vector <int>(26, 0));
        for (int i = 0; i < indegree.size(); i++) {
            if (indegree[i] == 0) {
                q.push(i);
                dp[i][colors[i] - 'a'] = 1;
            }
        }
        int cnt = 0;
        int ans = 0;
        while (!q.empty()) {
            int n = q.size();
            while (n--) {
                auto it = q.front();
                cnt++;
                ans = max(ans, dp[it][colors[it] - 'a']);
                q.pop();
                for (auto& itt : mp[it]) {

                    for (int k = 0; k < 26; k++) {
                        dp[itt][k] = max(
                            dp[itt][k], dp[it][k] + ((colors[itt] - 'a') == k));
                    }
                    indegree[itt]--;
                    if (indegree[itt] == 0) {
                        q.push(itt);
                    }
                }
            }
        }
        if (cnt != n)
            return -1;
        return ans;
    }
};