class Solution {
public:
    static bool cmp(pair<int, int>& p1, pair<int, int>& p2) {
        if (p1.first == p2.first) {
            return p1.second > p2.second;
        }

        return p1.first < p2.first;
    }
    long long maxTotal(vector<int>& value, vector<int>& limit) {
        int n = value.size();

        vector<pair<int, int>> vec;

        for (int i = 0; i < n; i++) {
            int x = value[i];
            int y = limit[i];
            vec.push_back({y, x});
        }
        long long ans = 0;

        sort(vec.begin(), vec.end(), cmp);

        int i = 0;
        while (i < vec.size()) {
            int x = vec[i].first;
            int y = vec[i].second;
            int cnt = x;
            while (i < n && (x == vec[i].first)) {
                if (cnt > 0) {
                    cnt--;
                    ans += vec[i].second;
                }
                i++;
            }
        }
        return ans;
    }
};

// you have to choose any i  (if and only if noActive<limit[i])
// after add value[i]
// and mark as active
// also if curactive x so block who have limit[j]<=x ( permanently block)

// basically it is optimal to use smallest one first
// ex 1,2  val[1,3]

// idea is suppose there is (1,5),(1,2),(1,7),(1,1);
// (1,7)

// (2,1),(2,6),(2,7)