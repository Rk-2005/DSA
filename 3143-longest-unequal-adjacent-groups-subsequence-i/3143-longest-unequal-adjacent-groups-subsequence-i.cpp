class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words,
                                         vector<int>& groups) {
        int n = words.size();
        int m = groups.size();
        vector<string> ans;
        int prev = groups[0];
        ans.push_back(words[0]);
        for (int i = 1; i < m; i++) {
            if (groups[i] != prev) {
                ans.push_back(words[i]);
            }
            prev = groups[i];
        }
        return ans;
    }
};

// 0 0 1 0