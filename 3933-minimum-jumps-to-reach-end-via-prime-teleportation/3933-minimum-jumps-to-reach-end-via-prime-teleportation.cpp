vector<bool> isPrime (1e6 + 1, true);
class Solution {
public:
     
   


    void seive() {
        isPrime[0] = 0;
        isPrime[1] = 0;
        for (int i = 2; i * i <= 1e6; i++) {
            if (isPrime[i]) {
                for (int p = i*i; p <= 1e6; p += i) {
                    isPrime[p] = 0;
                }
            }
        }
    }
    int minJumps(vector<int>& nums) {
        int n = nums.size();
        if(isPrime[0])seive();
        queue<int> q;
        int maxi = *max_element(nums.begin(), nums.end());
        q.push(0);
        vector<int> dp(n, -1);
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }
        dp[0]=0;
        unordered_set<int>used;
        while (!q.empty()) {

            int idx = q.front();
            q.pop();
            if (idx - 1 >= 0 && dp[idx - 1] == -1) {
                dp[idx - 1] = dp[idx] + 1;
                q.push(idx - 1);
            }

            if (idx + 1 < n && dp[idx + 1] == -1) {
                dp[idx + 1] = dp[idx] + 1;
                q.push(idx + 1);
            }

            if (!isPrime[nums[idx]] || used.find(nums[idx])!=used.end()) {
                continue;
            }

            for (int i = nums[idx]; i <= maxi; i += nums[idx]) {
                if (mp.find(i) == mp.end()) {
                    continue;
                }
                for (auto it : mp[i]) {
                    if (dp[it] != -1)
                        continue;

                    if (it == n - 1)
                        return dp[idx] + 1;
                    q.push(it);
                    dp[it] = dp[idx] + 1;
                }
            }
            used.insert(nums[idx]);
        }
        return dp.back();
    }
};