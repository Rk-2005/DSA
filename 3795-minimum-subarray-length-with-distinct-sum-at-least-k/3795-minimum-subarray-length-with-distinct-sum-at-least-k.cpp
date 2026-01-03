class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        int n = nums.size();

        map<int, int> mp;

        int ans = INT_MAX;

        int i = 0;
        int j = 0;

        int sum = 0;

        while (j < n) {
            int num = nums[j];

            if (mp[num]==0) {
                sum += num;
            }
            mp[num]++;

            while (i <= j && sum >= k) {

                mp[nums[i]]--;

                if (mp[nums[i]] == 0) {
                    sum -= nums[i];
                }

                ans = min(ans, j - i + 1);

                i++;
            }

            j++;
        }
        return (ans == INT_MAX ? -1 : ans);
    }
};

// 2 2 3 1
// 2 2 3 1
//