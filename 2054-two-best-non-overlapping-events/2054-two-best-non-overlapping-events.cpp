class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();

        sort(events.begin(), events.end());
        int ans = 0;

        vector<pair<int, int>> start;
        start.push_back({events[n - 1][0], events[n - 1][2]});

        for (int i = n - 2; i >= 0; i--) {
            auto it = start.back();

            start.push_back({events[i][0], max(it.second, events[i][2])});
        }
        reverse(start.begin(), start.end());


        
        for (auto& it : events) {
            cout<<"end is "<<it[1]<<" ";
            auto itt = lower_bound(start.begin(), start.end(),
                                   make_pair(it[1]+1, INT_MIN));
            
          
            ans = max(ans, it[2]);

            if (itt != start.end()) {
                cout<<"valus is "<<it[2]<<" upper bound "<<itt->second<<endl;
                ans = max(ans, it[2] + itt->second);
            }
        }

        return ans;
    }
};

// [1,3,2],[2,4,3],[4,5,2]

// [1,3,2],[2,4,3],[4,5,2]
//