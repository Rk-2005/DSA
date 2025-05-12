class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int n = digits.size();
        vector<int> ans;
        vector<int> temp(10, 0);
       
        for (int i = 0; i < n; i++) {
            temp[digits[i]]++;
        }

        vector<int>hello=temp;

        for (int i = 1; i < 10; i++) {
            int is = 0, is1 = 0, is2 = 0;
            if (temp[i] > 0) {
                temp[i]--;
            } else {
                continue;
            }
            for (int j = 0; j <= 9; j++) {
                if (temp[j] > 0) {
                    temp[j]--;
                }else{
                    continue;
                }

                for (int k = 0; k < 9; k += 2) {
                    if (temp[k] > 0){
                     int a = i * 100;
                    int b = j * 10;
                    int res = a + b + k;
                    ans.push_back(res);
                    }
                    else {
                        continue;
                    }
                    
                }
                temp[j]++;
            }
            temp[i]++;
            
        }

        return ans;
    }
};