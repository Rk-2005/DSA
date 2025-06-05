class Solution {
public:
    char DFS(char ch, unordered_map<char, vector<char>>& mp,
             vector<bool>& vis) {
        vis[ch - 'a'] = true;
        char c = ch;
        for (auto i : mp[ch]) {
            if (vis[i - 'a'] == 0) {
                c = min(c, DFS(i, mp, vis));
            }
        }

        return c;
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        unordered_map<char, vector<char>> mp;
        for (int i = 0; i < size(s1); i++) {
            mp[s1[i]].push_back(s2[i]);
            mp[s2[i]].push_back(s1[i]);
        }
        string res = "";
        for (int i = 0; i < size(baseStr); i++) {
            char ch = baseStr[i];
            vector<bool> vis(26, 0);
           // ab = ch;
            res.push_back(min(ch, DFS(ch, mp, vis)));
        }
        return res;
    }
};