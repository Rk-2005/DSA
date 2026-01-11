class Solution {
public:
    vector<int> FindPrevious(vector<int>& array) {
        int n = array.size();

        stack<int> st;

        st.push(-1);

        vector<int> ans(n, 0);

        for (int i = 0; i < n; i++) {
            while (st.top() != -1 && array[st.top()] >= array[i]) {
                st.pop();
            }

            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> FindNext(vector<int>& array) {
        int n = array.size();

        stack<int> st;

        st.push(n);

        vector<int> ans(n, 0);

        for (int i = n - 1; i >= 0; i--) {
            while (st.top() != n && array[st.top()] >= array[i]) { // 3 4 2
                st.pop();
            }

            ans[i] = st.top();
            st.push(i);
        }

        return ans;
    }
    int FindAns(vector<int>& array) {
        int sz = array.size();

        vector<int> left = FindPrevious(array);
        vector<int> right = FindNext(array);

        int MaxAns = 0;

        for (int i = 0; i < sz; i++) {
            int height = array[i];

            int width = right[i] - left[i] - 1;

            int currentAns = height * width;

            MaxAns = max(MaxAns, currentAns);
        }

        return MaxAns;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {

        int row = matrix.size();
        int col = matrix[0].size();

        vector<int> cols(col, 0);

        for (int i = 0; i < col; i++) {
            if (matrix[0][i] == '1') {
                cols[i] = 1;
            } else {
                cols[i] = 0;
            }
        }

        int MaxAns = FindAns(cols);

        for (int i = 1; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (matrix[i][j] == '1') {
                    cols[j] += 1;
                } else {
                    cols[j] = 0;
                }
            }
            for(auto it:cols){
                cout<<it<<" ";
            }
            cout<<endl;
            MaxAns = max(MaxAns, FindAns(cols));
        }

        return MaxAns;
    }
};

// 1 0 1 0 0

// 0 1 2 3 4 5
// 1 4 2 2 3 1

// 0 1 2 3 4 5
// 4 2 2 3 1 1

// height * () =

// 1 4 3 2

// 1 4 3 2
// -1 , 0 ,