class Solution {
public:
    vector<int> findGoodIntegers(int n) {

        map<long, long> mp;
        vector<int> ans;

        for (long long x = 1; x <= 1000; x++) {

            long long qbx = x * x * x;

            if (qbx > n) {
                break;
            }

            for (long long y = x + 1; y <= 1000; y++) {

                long long qby = y * y * y;

                if (qby > n) {
                    break;
                }

                long long add = qbx + qby;

                if (add > n) {
                    break;
                }

                mp[add]++;

                if (mp[add] == 2)
                    ans.push_back(add);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};

// a^3 + b^3 = x

// 1 + 1000