class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        string s2=to_string(num);
        char ch='&';
        char ch2='&';
        for(int i=0;i<s.size();i++){
            if(s[i]==ch){
                s[i]='9';
            }else if(s[i]!='9' && ch=='&'){
                ch=s[i];
                s[i]='9';
            }

            if(s2[i]==ch2){
                s2[i]='0';
            }else if(s2[i]!='0' && ch2=='&'){
                ch2=s2[i];
                s2[i]='0';
            }
        }
        int a=stoi(s);
        int b=stoi(s2);

        return a-b;
    }
};