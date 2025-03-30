class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> last(26, 0);
        int n = s.size();
        for (int i = 0; i < n; i++) {
            int num = s[i] - 'a';
            
            last[num] = i;
        }
        vector<int> ans;
        int end = last[s[0] - 'a'];
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            cnt++;
            end = max(end, last[s[i] - 'a']);
            if (i >= end) {
                ans.push_back(cnt);
                cnt = 0;
            }
        }
        return ans;
    }
};