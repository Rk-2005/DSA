class Solution {
public:
    string mini;

    void solve(string ans, string target, int idx, vector<int> temp) {

        if (idx >= target.size()) {
            //  cout << ans << " ";
            if (ans > target) {
                mini = min(mini, ans);
            }
            return;
        }

        if (temp[target[idx] - 'a'] > 0) {
            temp[target[idx] - 'a']--;
            ans.push_back(target[idx]);
            solve(ans, target, idx + 1, temp);
            ans.pop_back();
            temp[target[idx] - 'a']++;
        }

        for (int i = (target[idx] - 'a') + 1; i < 26; i++) {
            if (temp[i] > 0) {
                temp[i]--;
                ans.push_back(char(i + 'a'));
                for (int k = 0; k < 26; k++) {
                    while (temp[k]--) {
                        ans.push_back(char(k + 'a'));
                    }
                }
                mini = min(mini, ans);
                return;
            }
        }
    }

    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        int m = target.size();

        vector<int> temp(26, 0);
        sort(s.rbegin(), s.rend());
        mini = s;
        if (s <= target) {
            return "";
        }
        for (auto& it : s) {
            temp[it - 'a']++;
        }
        bool is = 0;
        string ans;
        solve(ans, target, 0, temp);
        return mini;
    }
};

//
// j  is ok
