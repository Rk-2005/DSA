class Solution {
public:
    bool isPrims(int num){
        if(num==0 || num==1 ){
            return false;
        }
        for(int i=2;i*i<=num;i++){
            if(num%i==0){
                return false;
            }
        }
        return true;
    }
    bool checkPrimeFrequency(vector<int>& nums) {
        int n = nums.size();
        map<int,int>mp;
        for(auto it:nums){
            mp[it]++;
        }
        for(auto it:mp){
            if(isPrims(it.second)){
                return 1;
            }
        }
        return 0;
    }
};