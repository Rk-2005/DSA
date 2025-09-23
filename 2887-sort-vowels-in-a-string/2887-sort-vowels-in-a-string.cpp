class Solution {
public:
    bool isVowel(char ch) {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
                ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U');
    }
    string sortVowels(string s) { 
        int n = s.size();

        int i = 0;

        vector<char>vowels;

        for(auto &it:s){
            if(isVowel(it))
            vowels.push_back(it);
        }

        sort(vowels.begin(),vowels.end());
       

        int j = 0;

        while(i<n){
            if(isVowel(s[i])){
                s[i]=vowels[j];
                j++;
            }
            i++;
        }
        return s;
     }
};

// first i will write function to check vowel or not

// then i will push vowels it into new array

// then simply i will apply sorting reverse
// at last take i pointer and simply place