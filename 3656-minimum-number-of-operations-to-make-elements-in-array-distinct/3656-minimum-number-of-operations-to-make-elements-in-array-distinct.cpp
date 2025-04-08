class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = size(nums);
        vector<int> cnt(101, 0);
        for (auto& it : nums) {
            cnt[it]++;
        }
        int ans = 0;
        int i = 0;
        while (i < n) {
            bool is = 0;
            for (int k = 0; k < 100; k++) {
                if (cnt[k] > 1) {
                    is = 1;
                    break;
                }
            }
            if (is == 0) {
                return ans;
            } else {
                int a = 3;
                while (i < n && a > 0) {
                    cnt[nums[i++]]--;
                    a--;
                }
                ans++;
            }
        }
        return ans;
    }
};