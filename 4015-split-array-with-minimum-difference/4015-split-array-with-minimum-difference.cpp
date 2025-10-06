class Solution {
public:
    long long splitArray(vector<int>& nums) {
        long long ans = 1e18;

        long long size = nums.size();

        vector<long long> leftsum(size, 0), rightsum(size, 0);

        vector<long long> rigthInc(size, 0);

        leftsum[0]=nums[0];

        for (int i = 1; i < size; i++) {

            leftsum[i] += leftsum[i - 1] + nums[i];
        }

        rightsum[size - 1] = nums[size - 1];

        rigthInc[size - 1] = 1;

        for (int i = size - 2; i >= 0; i--) {
            if (nums[i] > nums[i + 1] && rigthInc[i + 1] == 1) {
                rigthInc[i] = 1;
            }
            rightsum[i] = rightsum[i + 1] + nums[i];
        }
       
        for (int i = 0; i < size-1; i++) {
            long long leftSum = leftsum[i];
            long long rightSum = rightsum[i+1];
            if((i==0 || nums[i]>nums[i-1]) && rigthInc[i+1]==1){
                ans=min(ans,abs(rightSum-leftSum));
            }else if(i>0 && nums[i]<nums[i-1]){
                break;
            }
        }
        return ans==1e18?-1:ans;
    }
};
// 1 2 1 4 3
// 1

// 1 2 3 3

// 2 4 3
// 1 1 0
//   1 1 