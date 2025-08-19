class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();

        long long ans = 0;
        long long  i=0;

        while (i < n) {
            if (nums[i] == 0) {
                long long cnt = 0;
                while (i < n && nums[i] == 0) {
                    cnt++;
                    i++;
                }
                ans += (long long)(cnt * (cnt + 1) / 2);
            } else {
                i++;
            }
        }
        return ans;
    }
};