class Solution {
public:
    const long long mod=1e9+7;
    int lengthAfterTransformations(string s, int t) {
        int n = s.size();
        vector<int> count(26, 0);
        for (auto& it : s) {
            count[it - 'a']++;
        }
         
        for (int i = 0; i < t; i++) {
            vector<int> temp(26, 0);
            for (int j = 0; j < 26; j++) {
                if (j == 25) {
                    temp[0] = (temp[0] + count[j])%mod;
                    temp[1] = (temp[1] + count[j])%mod;
                } else {
                    temp[j + 1] = (temp[j + 1] + count[j])%mod;
                }
            }
            count = temp;
        }

        int ans = 0;
        for (auto it : count) {
            ans =(ans%mod+ it%mod)%mod;
        }
        return ans;
    }
};

// abcyy
//