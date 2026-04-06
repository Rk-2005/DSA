class Solution {
public:
    long long minIncrease(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0; // Cannot form any special index

        // Helper lambda to calculate the cost to make index 'i' special
        auto getCost = [&](int i) -> long long {
            long long target = max(nums[i - 1], nums[i + 1]) + 1LL;
            return max(0LL, target - nums[i]);
        };

        if (n % 2 != 0) {
            // ODD length: Only 1 valid configuration (pick all odd indices)
            long long cost = 0;
            for (int i = 1; i < n - 1; i += 2) {
                cost += getCost(i);
            }
            return cost;
            
        } else {
            // EVEN length: 1 skip allowed (transition from odds to evens)
            int k = (n - 2) / 2;
            long long current_cost = 0;
            
            // Initial window: assume we pick ALL even indices
            for (int i = 1; i <= k; ++i) {
                current_cost += getCost(2 * i);
            }
            
            long long min_cost = current_cost;
            
            // Slide the transition point: swap the even index for an odd index pair by pair
            for (int i = 1; i <= k; ++i) {
                current_cost -= getCost(2 * i);      // Remove the even index
                current_cost += getCost(2 * i - 1);  // Add the odd index
                
                min_cost = min(min_cost, current_cost);
            }
            
            return min_cost;
        }
    }
};