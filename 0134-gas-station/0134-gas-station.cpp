class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int bal = 0;
        int curcost = 0;
        int ans = 0;
        int kul = 0;
        for (int i = 0; i < n; i++) {
            bal += (gas[i] - cost[i]);
            if (bal < 0) {
                kul += bal;
                bal = 0;
                ans = i + 1;
            }
        }
        if (bal + kul < 0) {
            return -1;
        }
        return ans;
    }
};

// 1 2 3 4 5
// 3 4 5 1 2
// -2 -4 -6 3 6

// 1 4 2 2
// 3 3 3 1
//-2 1 -1 1
