class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string, int> mp;
        for (auto& word : words) {
            mp[word]++;
        }

        int ans = 0;
        bool hasCenter = false;

        for (auto& [word, count] : mp) {
            string rev = word;
            reverse(rev.begin(), rev.end());

            if (word == rev) {
                // Handle words like "aa", "bb"
                ans += (count / 2) * 4;
                if (count % 2) hasCenter = true;
            } else if (word < rev && mp.find(rev) != mp.end()) {
                // Handle distinct pairs like "ab" and "ba"
                int pairs = min(count, mp[rev]);
                ans += pairs * 4;
                // Mark them as used
                mp[word] -= pairs;
                mp[rev] -= pairs;
            }
        }

        if (hasCenter) ans += 2; 

        return ans;
    }
};
