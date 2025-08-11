class Solution {
public:
    void checksum(int target, int idx, vector<vector<int>>& ans,
                  vector<int>& nums) {
        int n = nums.size();

        int i = idx+1;
        int j = n - 1;
        while (i < j) {
           
           

            long long sum = nums[i] + nums[j];

            if (sum > target) {
                j--;
            } else if (sum < target) {
                i++;
            } else {
                while (i + 1 < n && nums[i] == nums[i + 1]) {
                    i++;
                }
                while (j - 1 >= 0 && nums[j] == nums[j - 1]) {
                    j--;
                }

                vector<int> temp = {nums[i], nums[j], nums[idx]};

                sort(temp.begin(), temp.end());

                ans.push_back(temp);
                i++;
                j--;
            }
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());
        for(auto it:nums){
            cout<<it<<" ";
        }
        cout<<endl;
        vector<vector<int>> ans;

        for (int i = 0; i < n; i++) {
            int target = -nums[i];

            
            cout<<target<<endl;
            checksum(target, i, ans, nums);
            while (i + 1 < n && nums[i] == nums[i + 1]) {
                i++;
            }
           
        }
        return ans;
    }
};

//  [1,1,2,3,4,4]
// target as 5