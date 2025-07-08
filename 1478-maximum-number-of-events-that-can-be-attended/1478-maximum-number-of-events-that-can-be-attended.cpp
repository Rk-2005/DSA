class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n = events.size();

        sort(begin(events), end(events)); // [4,5],[1,5]
        priority_queue<int, vector<int>, greater<int>> pq;

        int i = 0;
        int d = events[i][0];
        int ans = 0;
        while (!pq.empty() || i < n) {

            if(pq.empty()){
                d= events[i][0];
            }
            while (i < n && d == events[i][0]) {
                pq.push(events[i][1]);
                i++;
            }

            while(!pq.empty() && pq.top()<d){
                pq.pop();
            }
            if (!pq.empty()) {
                pq.pop();
                ans++;
            }

            d++;
        }
        return ans;
    }
};