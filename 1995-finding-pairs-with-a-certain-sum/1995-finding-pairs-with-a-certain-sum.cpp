class FindSumPairs {
public:
    map<int, int> mp1, mp2;
    vector<int> nums3;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        nums3 = nums2;
        for (auto& it : nums1) {
            mp1[it]++;
        }
        for (auto& it : nums2) {
            mp2[it]++;
        }
    }

    void add(int index, int val) {
        int num = nums3[index];
        mp2[num]--;
        if (mp2[num] == 0) {
            mp2.erase(num);
        }
        num += val;
        nums3[index]=num;
        mp2[num]++;
    }

    int count(int tot) {
        int ans = 0;
        for (auto it : mp1) {
            int no = it.first;
            int freq = it.second;
            int To_Find = tot - no;
            if (mp2.find(To_Find) != mp2.end()) {
                ans += (freq * mp2[To_Find]);
            }
        }

        return ans;
    }
};

//  1-2
//  2->1
/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */

// 1 1 2 2 2 3 , []