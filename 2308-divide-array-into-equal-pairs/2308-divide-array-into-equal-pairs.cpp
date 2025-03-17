class Solution {
public:
    bool divideArray(vector<int>& nums) {
        vector<int>temp(501,0);
        for(auto &it:nums){
            temp[it]++;
        }
        
        for(auto &it:temp){
            if(it%2!=0)return 0;
        }

        return 1;
    }
};