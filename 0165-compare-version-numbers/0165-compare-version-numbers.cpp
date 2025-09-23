class Solution {
public:
    vector<int> gets(string version){
        
        stringstream ss(version);

        vector<int>ans;

        string token;

        while(getline(ss,token,'.')){
            ans.push_back(stoi(token));
        }
        return ans;
    }
    int compareVersion(string version1, string version2) {
        int n = version1.size();
        
        

        vector<int>s1=gets(version1);
        vector<int>s2=gets(version2);

        int i=0;
        int j=0;
        while(i<s1.size() || j<s2.size()){
            int a=(i<s1.size())?s1[i]:0;
            int b=(j<s2.size())?s2[i]:0;

            if(a<b){
                return -1;
            }else if(a>b){
                return 1;
            }
            i++;
            j++;
        }
        return 0;

    }
};