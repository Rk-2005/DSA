class Solution {
public:
    void dfs(int src,vector<bool>&vis,int &v,int &e,unordered_map<int,vector<int>>&mp){
        v++;
        e+=mp[src].size();
        vis[src]=1;
        for(auto it:mp[src]){
            if(vis[it]==false){
                dfs(it,vis,v,e,mp);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>>mp;
        for(auto &it:edges){
            int x=it[0],y=it[1];
            mp[x].push_back(y);
            mp[y].push_back(x);
        }
        int ans=0;
        vector<bool>vis(n,0);
        for(int i=0;i<n;i++){
            if(vis[i]==false){
                int v=0;
                int e=0;
                dfs(i,vis,v,e,mp);
                if(v*(v-1)==e){
                    ans++;
                }
            }
        }
        return ans;
    }
};

