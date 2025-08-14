class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.size();
        int maxi = 0;
        char ch=' ';

        int i = 0;
        while (i < n) {
            char ele = num[i];
            int c = 0;
            while (i < n && ele == num[i]) {
                c++;
                i++;
            }
            if (c >= 3) {
                if (ele > ch) {
                    ch = ele;
                }
            }
        }
        if(ch==' '){
            return "";
        }
        
        return string(3, ch);
    }
};