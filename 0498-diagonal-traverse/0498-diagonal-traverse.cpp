class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        map<int, vector<int>> mp;
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int sum = i + j;
                mp[sum].push_back(mat[i][j]);
            }
        }
        for (int i = 0; i < n * m; i++) {
            auto vec = mp[i];
            if (i % 2 == 0) {
                reverse(vec.begin(), vec.end());
            }
            for (auto& it : vec) {
                ans.push_back(it);
            }
        }
        return ans;
    }
};