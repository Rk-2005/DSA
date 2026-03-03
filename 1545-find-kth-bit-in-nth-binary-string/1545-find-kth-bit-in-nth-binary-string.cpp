class Solution {
public:
    char findKthBit(int n, int k) {
        if (n == 1 && k == 1) {
            return '0';
        }
        int len = pow(2, n) - 1;
        int mid = (len + 1) / 2; // 4
        if (k == mid) {
            return '1';
        } else if (k < mid) {
            return findKthBit(n - 1, k);
        }
        char ch=findKthBit(n-1,pow(2,n-1)-(k-mid));
        return (ch=='0')?'1':'0';  
    }
};