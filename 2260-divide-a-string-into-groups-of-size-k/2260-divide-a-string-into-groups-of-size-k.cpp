class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n = s.size();

        vector<string> ans;
        string t = "";
        int i = 0;
        while (i < n) {
            char ch = s[i];
            int temp = k;

            while (i < n && temp > 0) {
                t += s[i];
                i++;
                temp--;
            }
            if (t.size() == k) {
                ans.push_back(t);
                t = "";
            }
        }
        while (!t.empty() && t.size() != k) {
            t += fill;
        }
        if (t.size() == k) {
            ans.push_back(t);
            t = "";
        }

        return ans;
    }
};