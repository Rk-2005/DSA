class Solution {
public:
    vector<int> findCoins(vector<int>& numWays) {
        int n = numWays.size();

        vector<int>temp(n+1,0);
        temp[0]=1;
        vector<int>ans;
        for(int i=0;i<n;i++){
            int cnt=numWays[i];
            int idx=i+1;

            if(cnt==0 && temp[idx]>0){
                return {};
            }

            if(temp[idx]==cnt){
                continue;
            }else{
                ans.push_back(idx);
                for(int i=1;i<=n;i++){
                    if((i-idx)>=0){
                        temp[i]+=temp[i-idx];
                    }
                }
            }
        
        }
        for(int i=1;i<=n;i++){
            if(temp[i]!=numWays[i-1]){
                return {};
            }
        }
        return ans;
    }
};

// numways[i] 
//