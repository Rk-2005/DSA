class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& c, int ex) {
        int n = c.size();

        int i = 0;
        vector<double>cur(n);
        priority_queue<pair<pair<double, int>, pair<int, int>>> pq;
        for (auto& it : c) {
            double val1 = double(double(it[0]) / double(it[1]));
            cur[i]=val1;
            double val2 = double(double(it[0] + 1) / double(it[1] + 1));
            pq.push({{val2 - val1, i}, {it[0]+1, it[1]+1}});
            i++;
        }

        while (ex--) {
            auto it = pq.top();
            pq.pop();
            cur[it.first.second] += it.first.first;
            int x=it.second.first;
            int y=it.second.second;
            double val1 = double(double(x) / double(y));
            double val2 = double(double(x + 1) / double(y + 1));
            pq.push({{val2 - val1, it.first.second}, {x+1, y+1}});
        }
        double res = 0;
        for (auto it : cur) {
            res += it;
        }
        return (res / n);
    }
};