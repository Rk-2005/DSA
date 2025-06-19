class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n = nums.size();

        // step 1 sort
        sort(nums.begin(), nums.end());

        // step 2 looping
        int mini = nums[0];
        int maxi = nums[0];
        int answer = 0;
        for (int i = 0; i < n; i++) {
            mini = min(nums[i],mini);
            maxi=  max(nums[i],maxi);
            int dif = maxi-mini;
            if(dif<=k){
                continue;
            }else{
                answer++;
                mini=nums[i];
            }
        }
        return answer+1;
    }
};
// 1 2
// ans=0
// 1 2 3 5 6 k = 2
// [1 2 3] // ans+=1
// 5-5=0 6-6=0
// x1 x2 x3 x4 ... xn
//  x2-x1<=k x3-x2<=k but x3-x1>k
// 1 3 5