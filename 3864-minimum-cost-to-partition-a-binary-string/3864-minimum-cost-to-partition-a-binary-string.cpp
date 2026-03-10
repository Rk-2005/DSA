class Solution {
public:
    long long solve(long long s, long long e, int& ec, int& fc,
                    vector<long long>& prefix) {
        if (s > e) {
            return 0;
        }
        long long len = e - s + 1;
        long long sensitive = prefix[e] - (s - 1 >= 0 ? prefix[s - 1] : 0);
        long long ans;

        if (sensitive == 0) {
            ans = fc;
        } else {
            ans = len * sensitive * ec;
        }

        if (len % 2 == 0) {
            long long mid = (s + e) / 2;

            ans = min(ans, solve(s, mid, ec, fc, prefix) +
                               solve(mid + 1, e, ec, fc, prefix));
        }

        return ans;
    }

    long long minCost(string s, int ec, int fc) {
        long long ans = 0;
        int n = s.size();

        vector<long long> prefix(n, 0);

        prefix[0] = (s[0] == '1' ? 1 : 0);

        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + (s[i] - '0');
        }

        return solve(0, n - 1, ec, fc, prefix);
    }
};

// encCost flatCost

// s[i]=='1' ith ele is sensitive
// s[i]=='0' ith ele is not sensitive

//  x==0 flat cost
// x>0

// 1010 - 4*2*3 = 24
// 10 10 - 1*3*2 = 6*2 = 12

// if len odd - cost will be Len * (no of sensitive)*(encost)
// if no sensitive element present then my cost directly falt cost right

// if len is even -

// 0011 f=2 encost = 3 4*2*3 = 24
// 00  11 - 2 + (2*2*3) = 2+12=14
// 0 0 1 1   = 2 + 2 + 3 + 3 = 10

// 0011
//  -
//