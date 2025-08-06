class Solution {
public:
    int minTime(string s, vector<int>& order, int k) {
        int n = s.size();

        set<long long> st;
        st.insert(-1);
        st.insert(n);
        long long  ans = 0;

        for (int i = 0; i < n; i++) {
            int temp = order[i];

            auto it = st.lower_bound(temp);
            int a = *it - 1;
            cout<<a<<" ";
            it--;
            int b = *it + 1;
            cout<<b<<" ";
            cout<<temp<<" ";
            cout<<endl;
            long long id1=(a-temp)+1;
            long long id2=(temp-b)+1;
            ans += id1*id2;
            st.insert(temp);
            if(ans>=k){
                return i;
            }
        }
        return -1;
    }
};