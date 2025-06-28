class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        vector<int>ans(n,INT_MAX);

        for (int i = 0; i < n; i++) {
            pq.push({nums[i], i});
            if (pq.size() > k) {
                pq.pop();
            }
        }
        while(!pq.empty()){
            auto it=pq.top();
            ans[it.second]=it.first;
            pq.pop();
        }
        vector<int>ans2;
        for(auto &it:ans){
            if(it!=INT_MAX){
                ans2.push_back(it);
            }
        }
        return ans2;

        return ans;
    }
};

//