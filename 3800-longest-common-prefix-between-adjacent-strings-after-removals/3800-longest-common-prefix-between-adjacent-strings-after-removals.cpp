class Solution {
public:
    int findMax(string& s, string& t) {
        int n = s.size();
        int m = t.size();
        int i = 0, j = 0;
        int ans = 0;
        while (i < n && j < m) {
            if (s[i] != t[j]) {
                return i;
            }
            i++;
            j++;
        }
        return min(i, j);
    }
    vector<int> longestCommonPrefix(vector<string>& words) {
        int n = words.size();
        vector<int> ans(n);
        int a = 0;
        int b = 0;
        int idx = 0;
        for (int i = 0; i < n - 1; i++) {
            int maxi = findMax(words[i], words[i + 1]);
            if (maxi > a) {
                b = a;
                idx = i;
                a = maxi;
            } else {
                b = max(b, maxi);
            }
        }
        
        for (int i = 0; i < n; i++) {
            if (i == idx || i == idx + 1) {
                int res = 0;
                if (i+1<n && i>0) {
                    res=findMax(words[i-1],words[i+1]);
                }
                ans[i] = max(res,b);
            } else {
                int res = 0;
                if (i+1<n && i>0) {
                    res=findMax(words[i-1],words[i+1]);
                }
                ans[i] = max(res,a);
            }
        }
        return ans;
    }
};
//   0   1   2   3
// jump run  jump j
