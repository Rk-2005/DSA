class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int n = nums.size();
        sort(begin(nums), end(nums));
        int ans = 0;
        int maxrange = nums[0]-k;
        int i=0;
        while (i < n) {
            int num = nums[i];
            int cnt = 0;
            int small = max(maxrange, num - k);
            int large = num + k;
            while (i < n && nums[i] == num) {
                i++;
                cnt++;
            }
            maxrange =min(small+cnt,large+1);
            ans += min(cnt, large - small + 1);
            
        }

        return ans;
    }
};