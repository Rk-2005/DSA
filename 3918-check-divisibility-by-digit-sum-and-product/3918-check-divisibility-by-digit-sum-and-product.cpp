class Solution {
public:
    bool checkDivisibility(int n) {
        string s = to_string(n);

        int sum = 0;
        long long p = 1;
        for (int i = 0; i < (s).size(); i++) {
            int noo = s[i] - '0';
            sum += noo;
            p *= noo;
        }

        return (n%(sum + p) == 0);
    }
};