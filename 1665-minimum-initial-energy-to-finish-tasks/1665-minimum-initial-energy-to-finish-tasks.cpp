class Solution {
public:
    static bool cmp(vector<int>& v1, vector<int>& v2) {
        return (v1[1] - v1[0]) > (v2[1] - v2[0]);
    }

    bool check(int mid, vector<vector<int>>& tasks) {

        for (auto& it : tasks) {
            if (it[1] <= mid) {
                mid = mid - it[0];
            } else {
                return false;
            }
        }

        return 1;
    }

    int minimumEffort(vector<vector<int>>& tasks) {
        int sz = tasks.size();

        sort(tasks.begin(), tasks.end(), cmp);

        int s = 0;

        int e = 0;

        for (auto& it : tasks) {
            e += it[1];
        }

        int ans = 0;

        while (s <= e) {

            int mid = s + (e - s) / 2;

            if (check(mid, tasks)) {
                ans = mid;
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }

        return ans;
    }
};

// actual , mini

// 1,2 -- 2,3 -- 4,5

//