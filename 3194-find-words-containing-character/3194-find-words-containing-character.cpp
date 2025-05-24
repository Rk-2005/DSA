class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        int n = words.size();
        vector<int> ans;
        auto lambda = [x](char ch) { return ch == x; };
        for (int i = 0; i < n; i++) {
            string s = words[i];
            if (any_of(begin(s), end(s), lambda) == true) {
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};