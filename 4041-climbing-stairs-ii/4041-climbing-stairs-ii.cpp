class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        

        vector<long long> temp(n, INT_MAX);
        temp[0] = costs[0] + 1;

        for (int i = 1; i < n; i++) {

            long long num = costs[i];
            long long c1 = 1 + num + temp[i - 1];
            long long c2 = INT_MAX;
            long long c3 = INT_MAX;
            if (i <= 2) {
                c3 = (i + 1) * (i + 1) + num;
            }

            if (i - 2 >= 0) {
                c2 = temp[i - 2] + num + (4);
            }

            if (i - 3 >= 0) {
                c3 = temp[i - 3] + num + 9;
            }
            
            temp[i] = min({c1, c2, c3});
        }
        return temp[n - 1];
    }
};

//  2 3 4 5