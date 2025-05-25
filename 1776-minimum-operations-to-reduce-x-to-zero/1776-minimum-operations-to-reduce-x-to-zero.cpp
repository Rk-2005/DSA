
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        
        map<int, int> suffix;

        int sum = 0;

        int ans = INT_MAX;

        for (int i = n - 1; i >= 0; i--) {
            sum += nums[i];
            if (sum == x) {
                ans = min(ans, n - i);
            }
            suffix[sum] = i;
        }

        if (sum < x)
            return -1;
        if (sum == x) {
            return n;
        }

        sum = 0;
        
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            int curpos =i;
            if (sum > x) {
                break;
            }
            if (sum == x) {
                ans = min(ans, curpos + 1);
            } else {
                int req = x - sum;
                if (suffix.find(req) != suffix.end()) {
                    int res = (curpos + 1) + (n - suffix[req]);
                    ans = min(res, ans);
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};