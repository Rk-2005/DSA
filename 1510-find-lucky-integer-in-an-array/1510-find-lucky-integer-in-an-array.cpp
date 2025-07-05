class Solution {
public:
    int findLucky(vector<int>& arr) {
        int n = arr.size();
        map<int,int>mp;
        for(auto it:arr){
            mp[it]++;
        }
        int  ans=-1;
        for(auto it:mp){
            if(it.first==it.second){
                ans=it.first;
            }
        }
        return ans;
    }
};