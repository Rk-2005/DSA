class Solution {
public:
  //  a,0 ,a,1
   struct comp {
    bool operator()(pair<char,int>& p1, pair<char,int>& p2) {
        
        if (p1.first == p2.first) {
            return p2.second > p1.second; // descending
        }
        return p1.first > p2.first;       // ascending
    }
};

    string clearStars(string s) {
        int n=s.size();
        priority_queue<pair<char,int>,vector<pair<char,int>>,comp>pq;
        
        for(int i=0;i<n;i++){
            if(s[i]=='*'){
                if(!pq.empty()){
                    pq.pop();
                }
            }else
            pq.push({s[i],i});

        }
        string t="";
        vector<pair<int,char>>idx;
        while(!pq.empty()){
            auto it=pq.top();
            idx.push_back({it.second,it.first});
            pq.pop();
        }
        sort(begin(idx),end(idx));
        for(auto it:idx){
            t+=it.second;
        }
        return  t;
    }
};