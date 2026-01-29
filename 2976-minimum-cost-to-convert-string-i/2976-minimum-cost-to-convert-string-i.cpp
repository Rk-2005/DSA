class Solution {
public:
    void dfs(char ch, vector<int>& fill, unordered_map<char, vector<pair<char, int>>>& mp) {
        priority_queue<pair<int, char>, vector<pair<int, char>>, greater<pair<int, char>>> pq;
        pq.push({0, ch});
        fill[ch - 'a'] = 0; // Correct indexing
        while (!pq.empty()) {
            int d = pq.top().first;
            char curr = pq.top().second;
            pq.pop();
            for (auto adj : mp[curr]) {
                char a = adj.first;
                int dist = adj.second;
                if (d + dist < fill[a - 'a']) {
                    fill[a - 'a'] = d + dist;
                    pq.push({d + dist, a});
                }
            }
        }
    }

    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        unordered_map<char, vector<pair<char, int>>> mp;
        for (int i = 0; i < original.size(); i++) {
            mp[original[i]].push_back({changed[i], cost[i]});
        }

        vector<vector<int>> fill(26, vector<int>(26, INT_MAX));
        for (int i = 0; i < 26; i++) {
           
            dfs('a' + i, fill[i], mp); // Start DFS from each character 'a' to 'z'
            
        }

        long long ans = 0;
        for (int i = 0; i < source.size(); i++) {
            if (target[i] == source[i]) continue;
            int srcIdx = source[i] - 'a';
            int tgtIdx = target[i] - 'a';
            if (fill[srcIdx][tgtIdx] == INT_MAX) {
                return -1; // Transformation not possible
            }
            ans += fill[srcIdx][tgtIdx];
        }
        return ans;
    }
};
