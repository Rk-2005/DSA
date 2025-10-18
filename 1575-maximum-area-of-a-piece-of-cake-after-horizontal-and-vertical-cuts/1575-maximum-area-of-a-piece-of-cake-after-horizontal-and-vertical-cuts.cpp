class Solution {
public: 
    const int mod = 1e9 + 7;
    int maxArea(int h, int w, vector<int>& hori, vector<int>& verti) {
        long long int n = hori.size();
        long long int m = hori.size();

        hori.push_back(0);
        hori.push_back(h);

        verti.push_back(0);
        verti.push_back(w);

        sort(hori.begin(), hori.end());
        sort(verti.begin(), verti.end());

        long long int MaxHoriDist = 0;
        long long int MaxVertiDist = 0;

        for (int i = 1; i < hori.size(); i++) {
            long long int a = hori[i] - hori[i - 1];
            MaxHoriDist = max(MaxHoriDist, a);
        }

        for (int i = 1; i < verti.size(); i++) {
            long long int b = verti[i] - verti[i - 1];
            MaxVertiDist = max(MaxVertiDist, b);
        }
        long long int ans = (MaxVertiDist * MaxHoriDist)%mod;

        return ans;
    }
};