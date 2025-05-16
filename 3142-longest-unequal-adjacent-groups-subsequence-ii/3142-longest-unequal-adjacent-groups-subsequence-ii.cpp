class Solution {
public:
    // abc // abc
    bool Dist(string &w1, string &w2) {
        int n = w1.size();
        int c = 0;
        for (int i = 0; i < n; i++) {
            if (w1[i] != w2[i]) {
                c++;
            }
        }
        return c == 1;
    }
    vector<string> getWordsInLongestSubsequence(vector<string>& words,
                                                vector<int>& groups) {
        int n = words.size();

        vector<int> temp(n, 0);

        vector<int> store(n, -1);

        

        for(auto &it:temp)it=1;
        

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if ((words[i].length() == words[j].length()) &&
                    groups[i] != groups[j] &&
                    (Dist(words[i], words[j]) == true)) {
                        if(temp[i]<(temp[j]+1)){
                           temp[i]=temp[j]+1;
                           store[i]=j;
                        }
                }
            }
        }
        int idx=0;
        int maxi=0;
        for(int i=0;i<n;i++){
            if(temp[i]>maxi){
                maxi=temp[i];
                idx=i;
            }
        }
        for(auto it:store){
            cout<<it<<" ";
        }
        vector<string>result;
        result.push_back(words[idx]);
        while(store[idx]!=-1){
            result.push_back(words[store[idx]]);
            idx=store[idx];
        }
        reverse(begin(result),end(result));
        return result;
    }
};

