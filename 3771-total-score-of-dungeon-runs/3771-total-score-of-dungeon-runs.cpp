class Solution {
public:
    long long totalScore(int hp, vector<int>& damage, vector<int>& req) {
        int n = damage.size();

        long long cnt = 0;

        vector<long long> prefix(n + 1, 0);
        prefix[1] = damage[0];

        for (int i = 1; i < n; i++) {
            prefix[i + 1] += prefix[i] + damage[i];
        }
    

        for (int i = 0; i < n; i++) {

            int limit = hp - req[i];

            if (limit < 0 || damage[i] > limit) {
                continue;
            }

            int ItnaChalega = prefix[i + 1] - limit;

          

            auto it =
                lower_bound(prefix.begin(), prefix.begin() + i, ItnaChalega) -
                prefix.begin();

            cnt += ((i + 1) - it);
            
        }
        return cnt;
    }
};