class Solution {
public:
    vector<int>parent,rank;
    int find(int node){
        if(parent[node]==node){
            return node;
        }

        return parent[node]=find(parent[node]);
    }

    void unionn(int x,int y){
        int a=find(x);
        int b=find(y);
        if(a==b){
            return;
        }else if(rank[a]>rank[b]){
            parent[b]=a;
            rank[a]++;
        }else{
            parent[a]=b;
            rank[b]++;
        }
    }
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        parent.resize(n);
        rank.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        for(auto &it:edges){
            unionn(it[0],it[1]);
        }
        for(int i=0;i<n;i++){
            parent[i]=find(i);
        }
        map<int,int>mp;
        
        for(auto it:edges){
            if(parent[it[0]]!=parent[it[1]]){
                continue;
            }else{
                if(mp.find(parent[it[0]])!=mp.end()){
                    mp[parent[it[0]]]&=it[2];
                }else{
                    mp[parent[it[1]]]=it[2];
                }
                
            }
        }
        vector<int>ans;
        for(auto &it:query){
            int x=it[0];
            int y=it[1];
            if(parent[x]!=parent[y]){
                ans.push_back(-1);
            }else{
                ans.push_back(mp[parent[x]]);
            }
        }
        for(auto it:parent){
            cout<<it<<" ";
        }
        return ans;
    }
};