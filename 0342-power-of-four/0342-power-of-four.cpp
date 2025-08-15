class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0)return 0;
        double a = log(n)/log(4);
        int b = int(a);

        return a==b;
    }
};