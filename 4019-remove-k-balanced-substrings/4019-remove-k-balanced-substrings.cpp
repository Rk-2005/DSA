class Solution {
public:
    string removeSubstring(string s, int k) {
        int n = s.size();

        stack<pair<char, int>> st;

        for (int i = 0; i < n; i++) {
            if (!st.empty() && s[i] == st.top().first) {
                st.top().second++;
            } else {
                st.push({s[i], 1});
            }

            if (s[i] == ')' && st.size() >= 2) {
                auto top1 = st.top();
                st.pop();
                auto top2 = st.top();
                st.pop();

                if (top1.second == k && top2.second >= k) {
                    top2.second -= k;
                    if (top2.second > 0) {
                        st.push(top2);
                    }
                } else {
                    st.push(top2);
                    st.push(top1);
                }
            }
        }

        string ans;

        while (!st.empty()) {
            int c = st.top().second;
            while (c--)
                ans.push_back(st.top().first);
            st.pop();
        }

        reverse(ans.begin(),ans.end());

        return ans;
    }
};

// (((()