class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count = 1;
        int maj = nums[0];
        for (int i = 1; i < n; i++) {
            int num = nums[i];

            if (nums[i] != maj) {
                count--;
            } else {
                count++;
            }
            if (count == 0) {
                maj = nums[i];
                count = 1;
            }
        }
        return maj;
    }
};
// a = 3
// c=1
// a = 2
// c=0
// a=2
//

// n/2 c>