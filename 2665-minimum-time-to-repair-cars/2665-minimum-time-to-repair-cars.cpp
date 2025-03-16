class Solution {
public:
    typedef long long ll;
    bool check(vector<int>& ranks,ll mid, int cars){
        ll n=ranks.size();
        ll c=0;
        for(int i=0;i<n;i++){
            if(ranks[i]>mid){
                continue;
            }
            ll temp=sqrt(mid/ranks[i]);
            c+=temp;
        }
        return c>=cars;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        int n=ranks.size();

        long long  s=0;
        long long e=ll(*min_element(begin(ranks),end(ranks)))*ll(cars)*ll(cars);
        ll ans=0;
        while(s<=e){
            ll mid=s+(e-s)/2;
            if(check(ranks,mid,cars)){
                ans=mid;
                e=mid-1;
            }else{
                s=mid+1;
            }
        }
        return ans;
    }
};

// 16
// 1* 
// 4
// 10  8
// 4 2 3 1 