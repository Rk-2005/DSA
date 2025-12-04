class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.size();

        stack<char> st;

        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (directions[i] == 'R') {
                st.push(directions[i]);
            } else if (directions[i] == 'S') {
                while (!st.empty() && st.top() == 'R') {
                    ans++;
                    st.pop();
                }
                st.push('S');
            } else {
                if (!st.empty() && st.top() == 'R') {
                    ans += 2;
                    st.pop();
                    while (!st.empty() && st.top() == 'R') {
                        ans++;
                        st.pop();
                    }
                    st.push('S');
                } else if (!st.empty() && st.top() == 'S') {
                    ans++;
                }
            }
        }
        return ans;
    }
};

// RLRSLL

// R

// L
