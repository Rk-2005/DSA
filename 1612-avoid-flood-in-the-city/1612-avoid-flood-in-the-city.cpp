class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();

        map<int, int> mp;

        multiset<int> safe;

        vector<int> ans(n, 1);

        for (int i = 0; i < n; i++) {
            if (rains[i] == 0) {
                safe.insert(i);
                continue;
            }
            if (rains[i] > 0 && mp.find(rains[i])!=mp.end()) {
                auto it = safe.lower_bound(mp[rains[i]]);
                cout<<rains[i]<<" ";
                cout<<*it<<" ";
                cout<<endl;
                if (it == safe.end()) {
                    return {};
                } else {
                    int idx = *it;

                    ans[i]=-1;
                    ans[idx] = rains[i];
                    safe.erase(it);
                }

            } else {
                ans[i]=-1;
            }

            mp[rains[i]] = i;
        }
        return ans;
    }
};

//