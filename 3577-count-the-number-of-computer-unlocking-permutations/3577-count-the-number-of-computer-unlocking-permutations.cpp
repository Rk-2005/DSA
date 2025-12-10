class Solution {
public:
    const int mod = 1e9 + 7;
    long long fact(int n) {

        long long ans = 1;
        for (int i = 2; i <= n; i++) {
            ans = (ans * i) % mod;
        }

        return ans;
    }
    int countPermutations(vector<int>& com) {
        long long n = com.size();

        long long ans = 0;

        long long mini = *min_element(com.begin(), com.end());

        if (com[0] != mini || com[1] == mini) {
            return 0;
        }

        for (int i = 1; i < n; i++) {
            if (com[i] == mini) {
                return 0;
            }
        }

        long long find = fact(n - 1);

        return find;
    }
};