class Solution {
public:
    int maxFreqSum(string s) {
        vector<int> temp(26, 0);
        for (auto& it : s) {
            temp[it - 'a']++;
        }
        int maxi1 = 0;
        int maxi2 = 0;
        for (int i = 0; i < 26; i++) {
            if (i == 0 || i == ('e' - 'a') || i == ('i' - 'a') ||
                i == ('o' - 'a') || i == ('u' - 'a')) {
                maxi1 = max(maxi1, temp[i]);
            } else {
                maxi2 = max(maxi2, temp[i]);
            }
        }
        return maxi1 + maxi2;
    }
};