class Solution {
public:
    bool check(int mid, vector<int>& tasks, vector<int>& workers, int pills,
               int strength) {
        int n = tasks.size();
        multiset<int> ms(begin(workers), begin(workers) + mid);
        for (int i = mid - 1; i >= 0; i--) {
            int req = tasks[i];
            auto it = prev(ms.end());
            if (*it >= req) {
                ms.erase(it);
            } else if (pills <= 0) {
                return 0;
            } else {
                auto weak = ms.lower_bound(req - strength);
                if (weak == ms.end())
                    return 0;
                ms.erase(weak);
                pills--;
            }
        }
        return 1;
    }
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills,
                      int strength) {
        int n = tasks.size();
        int m=workers.size();
        sort(begin(tasks), end(tasks));
        sort(rbegin(workers), rend(workers));
        int s = 0, e = min(n,m);
        int ans = 0;
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (check(mid, tasks, workers, pills, strength)) {
                ans = mid;
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }
        return ans;
    }
};