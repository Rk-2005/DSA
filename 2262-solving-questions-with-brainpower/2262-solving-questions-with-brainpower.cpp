class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
        vector<long long>t(n);
        t[n-1]=questions[n-1][0];
        for(int i=n-2;i>=0;i--){
            int x=questions[i][0];
            int y=questions[i][1];
            t[i]=max(x+((i+y+1<n)?t[i+y+1]:0),t[i+1]);
        }
        
        return t[0];
    }
};