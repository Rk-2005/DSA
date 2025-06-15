class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);
        string t = to_string(num);

        char x1 = '&';
        char x2 = '&';
        bool first = 0;
        if (t[0] != '1') {
            x2 = t[0];
            first = 1;
            t[0] = '1';
        }
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == x1) {
                s[i] = '9';
            } else if (s[i] != '9' && x1 == '&') {
                x1 = s[i];
                s[i] = '9';
            }

            if (t[i] == x2) {
                if (first == 1) {
                    t[i] = '1';
                } else
                    t[i] = '0';
            } else if (t[i] != '0' && x2 == '&' && i != 0) {
                if (t[0] == '1' && t[i] == '1')
                    continue;
                x2 = t[i];
                t[i] = '0';
            }
        }
        cout << s << " " << t << " ";
        int a = stoi(s);
        int b = stoi(t);
        return a - b;
    }
};

// 8000
// 9000
// 8999