class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans;
        int carry = 0;
        reverse(begin(digits), end(digits));

        for (int i = 0; i < size(digits); i++) {

            int sum = (digits[i] + carry) ;
            if (i == 0)
                sum += 1;
                
            carry = sum / 10;
            ans.push_back(sum%10);
        }
        if (carry != 0)
            ans.push_back(1);
        reverse(begin(ans), end(ans));
        return ans;
    }
};