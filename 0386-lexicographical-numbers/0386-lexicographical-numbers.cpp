class Solution {
public:
    vector<int>ans;
    
    void f(int i,int n){
        for(int j=(i==0?1:0);j<=9;j++){
            int x=i*10+j;
            if(x>n)break;
            ans.push_back(x);
            f(x,n);
        }
    }
    vector<int> lexicalOrder(int n) {
        f(0,n);
        return ans;
    }
};