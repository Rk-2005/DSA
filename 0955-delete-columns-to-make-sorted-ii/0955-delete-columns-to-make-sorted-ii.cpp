class Solution {
public:
    int minDeletionSize(vector<string>& strs) {

        int n = strs.size();

        int m = strs[0].size();

        int result = 0;
        vector<bool> checked(n, 0);

        for (int i = 0; i < m; i++) {
            bool same = 0;
            bool foundans = 1;
            for (int j = 1; j < n; j++) {
                char cur = strs[j][i];
                if (checked[j] == true)
                    continue;

                if (cur < strs[j - 1][i]) {
                    cout << cur << " " << strs[j - 1][i] << " " << endl;
                    result++;
                    foundans = 0;
                    break;
                } else if (cur == strs[j - 1][i]) {
                    same = 1;
                }
            }

            if (foundans == 1 && same == 0) {
                break;
            }
            if (foundans == 1) {
                for (int j = 1; j < n; j++) {
                    char cur = strs[j][i];

                    if (cur > strs[j - 1][i]) {

                        checked[j] = true;
                    }
                }
            }
        }
        return result;
    }
};

// ans = 1
// ad,ab,dd
//
// acc bdd yzz xaa