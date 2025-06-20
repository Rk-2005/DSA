class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 0;
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            int num = nums[i];
             while (i+1 < size && num == nums[i + 1]) { 
                i++;
            } 
            nums[count] = num;
            count++;
        } 

        return count;
    }
};
