class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int maxi=nums[0];
        int count=0;
        for(int i=1;i<n;i+=0){
            int a=maxi;
            count++;
            while(i<n && i<=a){
                maxi=max(maxi,nums[i]+i);
                i++;
            }
        }
        return count;
    }
};