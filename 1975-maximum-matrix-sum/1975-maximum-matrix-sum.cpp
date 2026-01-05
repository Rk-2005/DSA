class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        int ans = INT_MIN;

        long long sum = 0;
        long long neg = 0;
        int mini = INT_MAX;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                mini = min(mini, abs(matrix[i][j]));

                if (matrix[i][j] < 0) {
                    neg++;
                }

                sum += abs(matrix[i][j]);
            }
        }

        if(neg%2==0)
        {
            return sum;
        }
        return (sum-abs(2*mini));
    }
};

// 18 - (2*1)