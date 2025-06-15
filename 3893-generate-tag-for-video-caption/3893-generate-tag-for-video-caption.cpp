class Solution {
public:
    string generateTag(string caption) {
        int n = caption.size();
        string t = "";
        t += '#';
        bool next = 0;
        int b=0;
        while(b<n && caption[b]==' '){
            b++;
        }
        for (int i = b; i < n; i++) {
            if (caption[i] == ' ') {
                next = 1;
                continue;
            }
            if (next == 1) {
                t += toupper(caption[i]);
                next = 0;
            } else {
                t += tolower(caption[i]);
            }
        }
        int a=t.size();
        return t.substr(0,min(a,100));
    }
};