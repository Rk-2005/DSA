class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> ans;
        string prev = "";
        for (string& f : folder) {
            if (prev.empty() || f.compare(0, prev.size(), prev) != 0 || f[prev.size()] != '/') {
                ans.push_back(f);
                prev = f;
            }
        }
        return ans;
    }
};
// a/b c/d a/b/c