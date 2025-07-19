class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int k = n / 3;

        priority_queue<int> pq;
        vector<long long> left(2 * k, 0);
        long long sum = 0;

        for (int i = 0; i < 2 * k; i++) {
            pq.push(nums[i]);
            sum += nums[i];
            if (pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }
            left[i] = sum;
        }

        priority_queue<int, vector<int>, greater<int>> pq2;
        vector<long long> right(n, 0);
        sum = 0;

        for (int i = n - 1; i >= k; i--) {
            pq2.push(nums[i]);
            sum += nums[i];
            if (pq2.size() > k) {
                sum -= pq2.top();
                pq2.pop();
            }
            right[i] = sum;
        }

        long long ans = LLONG_MAX;
        for (int i = k - 1; i < 2 * k; i++) {
            ans = min(ans, left[i] - right[i + 1]);
        }
        return ans;
    }
};
