class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int n = nums.size();

        int mini = *min_element(nums.begin(), nums.end());

        int maxi = *max_element(nums.begin(), nums.end());

        unordered_map<int, int> mp;

        for (auto& it : nums) {
            mp[it]++;
        }

        int ans = 0;

        sort(nums.begin(), nums.end());

        
        for (int i = mini; i <= maxi; i++) {
            int num = i;

            auto lowValue =
                lower_bound(nums.begin(), nums.end(), num - k) -
                nums.begin();

            auto highValue =
                upper_bound(nums.begin(), nums.end(), num + k) -
                nums.begin();
            int idx1 =lowValue;
            int idx2 =highValue;
            int res = (idx2-idx1)-mp[num];
           
            ans = max(ans, mp[num]+min(res,numOperations));
        }
        return ans;
    }
};

// 0 1 2 4
// 3 4 4 5 k=1
//

// idx2 idx1

// 0 1 2 3 
// 2 4 5 
/// 2-