class Solution {
public:
    bool isadj(char ch1, char ch2) {
        if (ch1 > ch2)
            swap(ch1, ch2);
        if ((ch1 == 'a' && ch2 == 'z'))
            return 1;
        int idx1 = ch1 - 'a';
        int idx2 = ch2 - 'a';
        return abs(idx1 - idx2) == 1;
    }
    string resultingString(string s) {
        int n = s.size();
        stack<char> st;
        for (int i = 0; i < n; i++) {
            char ch = s[i];
            if (!st.empty() && isadj(ch, st.top())) {

                st.pop();
            } else {
                st.push(s[i]);
            }
        }

        string ans = "";
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};