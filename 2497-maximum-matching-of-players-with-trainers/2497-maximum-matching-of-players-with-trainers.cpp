class Solution {
public:
    bool check(vector<int>& players,vector<int>& trainer,int target){
        int n = players.size();
        int m = trainer.size();
        int i = 0;
        int j = 0;

        while(i<n && j<m){
            if(players[i]<=trainer[j]){
                i++;
                j++;
            }else{
                j++;
            }
        }
        return i<=target;
    }
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int n = players.size();
        
        int s=0;
        int e=min(trainers.size(),players.size());
        sort(begin(players),end(players));
        sort(begin(trainers),end(trainers));
        int ans=0;

        while(s<=e){
            int mid  = s+(e-s)/2;

            if(check(players,trainers,mid)){
                ans=mid;
                e=mid-1;
            }else{
                s=mid+1;
            }
        }
        return ans;
    }
};
// 0
// 1
// 2 
// 3
// 4 
// 5 
// 6
// [3,4] , [5,2,3]
// 3>2 = > not pos