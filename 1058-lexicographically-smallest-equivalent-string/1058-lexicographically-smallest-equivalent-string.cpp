class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int parentt(int node) {
        if (parent[node] == node) {
            return node;
        }

        return parentt(parent[node]);
    }
    void unionn(int node1, int node2) {
        int p1 = parentt(node1);
        int p2 = parentt(node2);

        if (p1<p2) {
            rank[p1]++;
            parent[p2] = p1;
        } else {
            rank[p2]++;
            parent[p1] = p2;
        }
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        parent.resize(26);
        rank.resize(26);
        for (int i = 0; i < 26; i++) {
            parent[i] = i;
        }
        for (int i = 0; i < s1.size(); i++) {
            char ch1 = s1[i] - 'a';
            char ch2 = s2[i] - 'a';
            unionn(ch1, ch2);
        }
        for (int i = 0; i < 26; i++) {
            parent[i] = parentt(i);
        }

        for(int i=0;i<baseStr.size();i++){
            int no1=(baseStr[i]-'a');
            char ch1=char(parent[no1]+'a');
          //  cout<<ch1<<" ";
            baseStr[i]=min(baseStr[i],ch1);
        }
        //cout<<baseStr<<" ";

        return baseStr;
    }
};