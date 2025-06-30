class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        int i = 0;
        int j = 1;
        int ans = 0;
        while (j < n) {
            int maxElement = nums[j];
            int minElement = nums[i];
            int dif = maxElement - minElement;

            if (dif == 1) {
                ans = max(ans, j - i + 1);
            } else {
                while (i <= j && nums[j] - nums[i] > 1) {
                    i++;
                }
            }
            j++;
        }

        return ans;
    }
};

// 0 1 2 3 4 5 6
// 1 2 2 2 3 3 5 // 4