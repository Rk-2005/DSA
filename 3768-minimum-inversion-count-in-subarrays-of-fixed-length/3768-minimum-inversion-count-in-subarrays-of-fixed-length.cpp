#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;



class Solution {
public:
    long long minInversionCount(vector<int>& nums, int k) {
        int n = nums.size();

        long long ans = LLONG_MAX;
        if (k == 1)
            return 0;

        long long a = 0;
        ordered_set temp;

        // Initial window insert last element
        temp.insert({nums[n - 1], n - 1});
       
      

        // Build first sliding window
        for (int i = n - 2; i >= (n - k); i--) {
            long long num = nums[i];
            temp.insert({num, i});

            long long inv = temp.order_of_key({num, i});
            a += inv;

            
        }

     
        ans = a;

        long long i = n - k - 1;

        // Slide window to the left
        while (i >= 0) {
            long long toadd = nums[i];
            long long toremove = nums[i + k];

           

            // Remove effect of old element
            int abc = temp.order_of_key({toremove, i + k});
            int removekaro = temp.size() - 1 - abc;


            a -= removekaro;
          
         // FULL SCAN erase (WORKS ALWAYS with less_equal)
            temp.erase({toremove,i+k});

           

            // Add new element
            temp.insert({toadd, i});
            int addInv = temp.order_of_key({toadd, i});
            a += addInv;

          

            ans = min(ans, a);

            i--;
        }

        return ans;
    }
};
