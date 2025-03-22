class Solution {
public:
    vector<int>parent,rank;
    int find(int x){
        if(x==parent[x]){
            return x;
        }

        return parent[x]=find(parent[x]);
    }
    void unionn(int a,int b){
        int x=find(a);
        int y=find(b);
        if(x==y){
            return;
        }else if(rank[x]>rank[y]){
            rank[x]++;
            parent[y]=x;
        }else{
            rank[y]++;
            parent[x]=y;
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        
        parent.resize(n);
        rank.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        unordered_map<int, vector<int>> mp;
        for (auto& it : edges) {
            unionn(it[0],it[1]);
            mp[it[0]].push_back(it[1]);
            mp[it[1]].push_back(it[0]);
            
        }
        for(int i=0;i<n;i++)
        {
            parent[i]=find(i);
        }
        int ans = 0;
        map<int,int>mp2;
        for(int i=0;i<n;i++){
            mp2[parent[i]]++;
        }
        vector<int>ab(n,1);
        for(int i=0;i<n;i++){
            int p=parent[i];
            if(mp2[p]!=-1 && (mp2[p]-1)!=mp[i].size()){
               mp2[p]=-1;
            }
        }
        for(auto it:mp2){
           if(it.second!=-1){
            ans++;
           }
        }
        return ans;
    }
};

/// dsu

// 0 1 2
// 1 2 2 

// 2
// |
// 3
// |
// 1 ->
// |
// 0
