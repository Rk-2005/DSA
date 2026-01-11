class Solution {
public:
    // 1 2 6 6
    vector<int> prev_smallest(vector<int>& col_sum) {
        int n = size(col_sum);
        vector<int> ans(n);
        stack<int> st;
        st.push(-1);
        ans[0] = -1;
        for (int i = 0; i < n; i++) {
            while (st.top() != -1 && col_sum[st.top()] >= col_sum[i]) {
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> nxt_smallest(vector<int>& col_sum) {
        int n = size(col_sum);
        vector<int> ans(n);
        stack<int> st;
        st.push(n);
        ans[n - 1] = n;
        for (int i = n - 1; i >= 0; i --) {
            while (st.top() != n && col_sum[st.top()] >= col_sum[i]) {
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    // 5 6 1
    int find_ans(vector<int>& col_sum) {
        int n = size(col_sum);
        vector<int> nxts = nxt_smallest(col_sum);
        vector<int> prevs = prev_smallest(col_sum);
        for(auto it:nxts)cout<<it<<" ";
        cout<<endl;
        for(auto it:prevs)cout<<it<<" ";
        int ans = 0;
        for (int i = 0; i < col_sum.size(); i++) {

            ans = max(ans, col_sum[i] * (nxts[i] - prevs[i] - 1));
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
      
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> col_sum(m);
        for (int i = 0; i < m; i++) {
            col_sum[i] =( (matrix[0][i] - '0'));
        }
        int ans = find_ans(col_sum);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '0') {
                    col_sum[j] = 0;
                } else {
                    col_sum[j] += 1;
                }
            }
            ans = max(ans, find_ans(col_sum));
        }
        return ans;
    }
};