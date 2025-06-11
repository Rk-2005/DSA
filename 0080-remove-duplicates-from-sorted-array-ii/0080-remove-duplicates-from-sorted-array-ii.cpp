class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        for (int i = 0; i < n ; i++) {
            int num = nums[i];
            int c = 1;
            nums[count] = num;
            count++;
            while (i + 1 < n && nums[i + 1] == num) {
                c++;
                if (c <= 2) {
                    nums[count] = num;
                    count++;
                }
                i++;
            }
        }
        return count;
    }
};