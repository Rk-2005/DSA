class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int ans=0;
        unordered_map<int,int>mp;
        for(auto it:answers){
            mp[it]++;
        }
        for(auto it:mp){
            ans+=((it.second+it.first)/(it.first+1))*(it.first+1);
        }
        return ans;
    }
};
//
// 0 1 2
// 1 1 2
// 0,1->red
// 2->blue
// 0 1 3 4 