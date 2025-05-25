class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        stack<int>st;
        int ans=0;
        for(int i=0;i<n;i++){
            int num=nums[i];
            while(!st.empty() && num<st.top()){
                st.pop();
            }
            
            while(st.empty() || st.top()<num){
                if(num>0)ans++;
                st.push(num);
            }
        }
        return ans;
    }
};

// 1 ans=1
// 2 ans=1