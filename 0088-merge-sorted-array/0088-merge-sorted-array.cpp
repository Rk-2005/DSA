class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int curp = nums1.size() - 1;
        while (i >= 0 && j >= 0) {
            if (nums1[i] >= nums2[j]) {
                nums1[curp] = nums1[i];
                i--;
            } else {
                nums1[curp] = nums2[j];
                j--;
            }
            curp--;
        }
        while (j >= 0) {
            nums1[curp] = nums2[j];
            j--;
            curp--;
        }
        while (i >= 0) {
            nums1[curp] = nums1[i];
            i--;
            curp--;
        }
    }
};

//