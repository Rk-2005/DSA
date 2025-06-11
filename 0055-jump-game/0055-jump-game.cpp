class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int maxi=nums[0];
        for(int i=1;i<n;i++){
            if(i>maxi){
                return 0;
            }
            maxi=max(maxi,i+nums[i]);
        }
        return true;
    }
};

// 2 3 1 1 4
// 2   