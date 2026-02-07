class Solution {
public:
    int minimumDeletions(string s) {
        stack<char> st;
        int c = 0;
        for (int i = 0; i < size(s); i++) {
            if (s[i] == 'b') {
                st.push(s[i]);
            } else if (s[i] == 'a') {
                if (!st.empty() && st.top() == 'b') {
                    c++;
                    st.pop();
                }
            }
        }
        return c;
    }
};