#include <vector>
#include <map>

class Solution {
public:
    int minimumIndex(std::vector<int>& nums) {
        int n = nums.size();
        std::map<int, int> freqMap;
        int maxFreq = 0;
        int dominantElement = -1;

        // Step 1: Find the dominant element (element with the highest frequency)
        for (int num : nums) {
            freqMap[num]++;
            if (freqMap[num] > maxFreq) {
                maxFreq = freqMap[num];
                dominantElement = num;
            }
        }

        int leftCount = 0;
        int remainingCount = maxFreq;

        // Step 2: Find the minimum valid index
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == dominantElement) {
                leftCount++;
                remainingCount--;
            }

            // Check if both left and right parts are valid
            if ((leftCount * 2 > i + 1) && (remainingCount * 2 > n - i - 1)) {
                return i;
            }
        }
        
        return -1;
    }
};
