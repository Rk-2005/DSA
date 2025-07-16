class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;

        int n = nums.size();
        deque<int> dq;
        for (int i = 0; i < k; i++) {
            while (!dq.empty() && (nums[dq.back()] < nums[i])) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        ans.push_back(nums[dq.front()]);

        for (int i = k; i < n; i++) {
            while (!dq.empty() && ((nums[dq.back()] < nums[i]))) {// 1<1
                dq.pop_back();
            }

            while (!dq.empty() && (dq.front() < ((i - k) + 1))) {// 1<1
                dq.pop_front();
            }

            dq.push_back(i);

            ans.push_back(nums[dq.front()]);
        }

        return ans;
    }
};

// 1 3 -1 -3 5 3 6 7
// 3 -1

// deque - > front end
