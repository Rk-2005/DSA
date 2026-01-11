class Solution {
public:
    long long countPairs(vector<string>& words) {
        long long ans = 0;
        map<string, int> mp;

        for (int i = 0; i < words.size(); i++) {
            string target = words[i];
            int a=26;
            while (a--) {
                for (int j = 0; j < target.size(); j++) {
                    int new_idx = (target[j] - 'a' + 1) % 26;
                    target[j] = char(new_idx + 'a');
                }
                if (mp.find(target) != mp.end()) {
                    ans += mp[target];
                }
            }
            mp[words[i]]++;
        }
        return ans;
    }
};

// [efgh,abcd]

// efgh - mp[efgh]=1;

//  abcd
//  bcde
//
