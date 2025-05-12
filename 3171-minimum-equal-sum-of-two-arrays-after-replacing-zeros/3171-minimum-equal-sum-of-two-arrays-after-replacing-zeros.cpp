class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long  n = nums1.size();
        long long m = nums2.size();
        long long c1 = 0;
        long long c2 = 0;
        long long sm1 = 0, sm2 = 0;
        for (int i = 0; i < n; i++) {
            if (nums1[i] == 0) {
                c1++;
            }
            sm1 += nums1[i];
        }
        for (int i = 0; i < m; i++) {
            if (nums2[i] == 0)
                c2++;
            sm2 += nums2[i];
        }
       // cout << sm1 << " " << c1 << " " << sm2 << " " << c2 << " ";

        if (sm1 == sm2) { // 20 - 20 0-3 c1/9
        if(c1==0 && c2!=0 || (c2==0&& c1!=0))return -1;
            if (c1 == c2)
                return sm2 + c2;
            return max(c1, c2) + sm1;
        } else if (sm1 + c1 > sm2 + c2) {
            if (c2 == 0) {
                return -1;
            } else {
                sm1 += c1;
                return sm1;
            }
        } else {
            if (c1 == 0) {
                return -1;
            } else {
                sm2 += c2;
                return sm2;
            }
        }
        return -1;
    }
};