class Solution {
public:
    vector<string> partitionString(string s) {
        int n = s.size();

        map<string,int>mp;
        vector<string>ans;
        string t="";
        for(int i=0;i<n;i++){
            t+=s[i];
            if(mp.find(t)==mp.end()){
                ans.push_back(t);
                mp[t]++;
                t="";
            }
        }
        return ans;
    }
};