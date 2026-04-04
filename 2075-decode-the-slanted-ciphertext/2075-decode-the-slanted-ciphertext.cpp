class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {

        int col = encodedText.size() / rows;

        string res;

        for (int i = 0; i < col; i++) {
            int r = i;

            while (r < encodedText.size()) {
                res.push_back(encodedText[r]);
                r += (col + 1);
            }
        }
        while(!res.empty() && res.back()==' '){
            res.pop_back();
        }
        
        return res;
    }
};