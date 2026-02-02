class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();
        // sum must include nums[0] initially
        long long sum = nums[0]; 
        k--; 

        set<pair<int, int>> st1, st2;

        // 1. Fill the initial window (Check bound i < n)
        for (int i = 1; i <= dist + 1 && i < n; i++) {
            st1.insert({nums[i], i});
            sum += nums[i]; // Add to sum immediately

            if (st1.size() > k) {
                auto ele = *st1.rbegin(); 
                sum -= ele.first; // Remove from sum immediately
                st2.insert(ele);
                st1.erase(prev(st1.end()));
            }
        }

        long long ans = sum;
        
        // 2. Slide the window
        // Start from dist + 2 because dist + 1 was handled in the first loop
        for (int i = dist + 2; i < n; i++) {
            // The element leaving the window is at index i - (dist + 1)
            int toremove = i - dist - 1;
            
            // --- REMOVAL LOGIC ---
            if (st1.count({nums[toremove], toremove})) {
                sum -= nums[toremove];
                st1.erase({nums[toremove], toremove});
            } else {
                st2.erase({nums[toremove], toremove});
            }

            // --- INSERTION LOGIC ---
            // Always insert into st1 first, then fix balance
            st1.insert({nums[i], i});
            sum += nums[i];

            // --- REBALANCE SIZE ---
            if (st1.size() > k) {
                auto ele = *st1.rbegin();
                sum -= ele.first;
                st2.insert(ele);
                st1.erase(prev(st1.end()));
            }

            // --- SWAP LOGIC (Make sum smaller) ---
            // Check !st2.empty() to prevent crash
            if (!st2.empty() && st1.rbegin()->first > st2.begin()->first) {
                auto big = *st1.rbegin();
                auto small = *st2.begin();
                
                sum -= big.first;
                sum += small.first;
                
                st1.erase(big);
                st2.erase(small);
                
                st1.insert(small);
                st2.insert(big);
            }
            
            ans = min(sum, ans);
        }

        return ans;
    }
};