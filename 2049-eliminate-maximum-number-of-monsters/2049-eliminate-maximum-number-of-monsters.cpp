class Solution {
public:
    int eliminateMaximum(vector<int>& arr, vector<int>& brr) {
        vector<int> dif;
        int n=arr.size();
        for (int i = 0; i < n; i++) {
            dif.push_back(((arr[i] + brr[i] - 1)) / brr[i]);
        }
    
        sort(dif.begin(),dif.end());
        for(auto it:dif){
            cout<<it<<" ";
        }
        int ans = 0;
        int cur = 0;
        for (int i = 0; i < n; i++) {

            if (dif[i] > cur) {
                ans++;
            } else {
                break;
            }
            cur += 1;
        }
        return ans;
    }
};