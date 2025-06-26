class Solution {
public:
    int findAns(unordered_map<int,vector<int>>&mp,vector<bool>& hasApple,vector<int>&vis,int node){

        vis[node]=1;
        int ans=0;
        for(auto &it : mp[node]){
            if(!vis[it]){
                ans+=findAns(mp,hasApple,vis,it);
            }
        }
        
        if(hasApple[node]==true || ans!=0){
            return 2+ans;
        }
        return 0;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        unordered_map<int,vector<int>>mp;

        for(auto it:edges){
            int x = it[0];
            int y=  it[1];
            mp[x].push_back(y);
            mp[y].push_back(x);
        }

        vector<int> vis(n);

        int ans= findAns(mp,hasApple,vis,0);
        
        if(ans!=0){
            ans-=2;
        }
        return ans;
    }
};

// 