class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(begin(meetings), end(meetings));
        int c = 0;
        int last = 1;
        for (int i = 0; i < meetings.size(); i++) {
            int s = meetings[i][0];
            int e = meetings[i][1];
            if (s > last) {
                c += i == 0 ? s - last : s - last - 1;
            }
            last = max(last, e);
        }

        if (days > last) {
            c += days - last;
        }
        return c;
    }
};