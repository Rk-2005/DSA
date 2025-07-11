class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        long long m = meetings.size();

        sort(meetings.begin(), meetings.end());

        map<long long, long long> mp1, mp2;

        mp1[0] = meetings[0][1];
        mp2[0]++;
        long long curTime = 0;
        for (int i = 1; i < m; i++) {
            auto meeting = meetings[i];

            long long st = meeting[0];
            long long end = meeting[1];

            curTime = st;

            long long curRoom = LLONG_MAX;
            long long idx = 0;

            bool is = 0;
            for (int j = 0; j < n; j++) {
                
                if (mp1.find(j) != mp1.end()) {
                    long long time = mp1[j];
                    if (time <= curTime) {
                        mp1[j] = end;
                        mp2[j]++;
                        is = 1;
                        break;
                    } else {
                        if (mp1[j] < curRoom) {
                            curRoom = mp1[j];
                            idx = j;
                        }
                    }
                } else {
                    is = 1;
                    mp2[j]++;
                    mp1[j] = end;
                    break;
                }
            }
            if (!is) {
                mp1[idx] = mp1[idx] + (end - st);
                mp2[idx]++;
            }
        }
        long long maxi = 0;
        long long idx = 0;
        for (auto it : mp2) {
           
            if (it.second > maxi) {
                maxi = it.second;
                idx = it.first;
            }
        }
        return idx;
    }
};
