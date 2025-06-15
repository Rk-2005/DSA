class Solution {
public:
    const long long mod=1e9+7;
    int specialTriplets(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        vector<long long> a1(n);
        map<long long , long long> mp1, mp2;
        
        for (auto& it : nums) {
            mp1[it]++;
        }
        for (int i = 0; i < n; i++) {
            long long num = (nums[i] * 2)%mod;
            long long prev = mp2[num];
            
            long long next = abs(prev - mp1[num]);
            if(nums[i]==0){
                next--;
            }
            ans += (prev * next)%mod;
            mp2[nums[i]]++;
        }
        return ans%mod;
    }
};
// nums[i] = nums[j]*2
// nums[k] = nums[j]*2
//