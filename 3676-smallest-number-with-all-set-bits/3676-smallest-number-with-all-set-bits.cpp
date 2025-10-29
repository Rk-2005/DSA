class Solution {
public:
    int smallestNumber(int n) {
      int pow=1;
      while(pow<=n){
        pow*=2;
      }  
      return pow-1;
    }
};

//2^1-1
