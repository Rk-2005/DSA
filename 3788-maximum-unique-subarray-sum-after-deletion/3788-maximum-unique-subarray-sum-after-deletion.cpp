class Solution {
public:
    int maxSum(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;
        int sum = 0;
        bool is = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0 && st.find(nums[i]) == st.end()) {
                sum += nums[i];
                is = 1;
                st.insert(nums[i]);
            }
        }
        if (is == 0) {
            sum = *max_element(begin(nums), end(nums));
        }
        return sum;
    }
};
// 1 4 1 5

//