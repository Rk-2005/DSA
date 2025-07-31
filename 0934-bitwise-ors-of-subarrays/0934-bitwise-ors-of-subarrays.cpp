class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        int n = arr.size();
        unordered_set<int>result,cur,prev;
        prev.insert(0);
        for(int i=0;i<n;i++){
            
            for(auto it:prev){
                cur.insert(it|arr[i]);
                result.insert(it|arr[i]);
            }

            cur.insert(arr[i]);
            prev=cur;
            prev.insert(0);
            cur.clear();
        }
        return result.size();
    }
};

// 1 2 3 4
// {1}, {2},{2,1}|