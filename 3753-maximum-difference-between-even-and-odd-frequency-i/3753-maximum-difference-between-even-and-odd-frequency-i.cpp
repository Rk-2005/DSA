class Solution {
public:
    int maxDifference(string s) {
        int n = s.size();
        vector<int> temp(26, 0);
        for (auto& it : s) {
            temp[it - 'a']++;
        }
        int maxi = 0;
        int mini = INT_MAX;
        for (auto& it : temp) {
            if(it%2!=0)
            maxi = max(it, maxi);
            if(it!=0 && it%2==0)
            mini = min(it, mini);
        }
        return maxi - mini;
    }
};