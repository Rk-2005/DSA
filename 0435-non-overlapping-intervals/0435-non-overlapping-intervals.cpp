class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        int n = intervals.size();

        sort(intervals.begin(), intervals.end());

        int last=intervals[0][1];

        int ans=0;

        for(int i=1;i<n;i++){
            if(intervals[i][0]<last){
                last=min(intervals[i][1],last);
                ans++;
            }else{
                last=intervals[i][1];
            }
        }
        return ans;
    }
};
// [1,2],[1,3],[2,3],[3,4]
// [1,4],[2,3],[4,5]

// first i will sort
// i will use custom sort
//