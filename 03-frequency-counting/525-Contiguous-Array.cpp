#include <unordered_map>
#include <vector>
using namespace std;
    // Time Complexity: O(n)
    // Space Complexity: O(n)
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        // Map to store the first index where a prefix sum appears
        unordered_map<int, int> pre_count;

        // Prefix sum 0 occurs before the array starts (index -1)
        pre_count[0] = -1;

        int pre_sum = 0;      // Running prefix sum
        int count = 0;        // Length of current valid subarray
        int max_count = 0;    // Maximum length found so far

        for (int i = 0; i < nums.size(); i++) {

            // Treat 0 as -1 and 1 as +1
            if (nums[i] == 0) {
                pre_sum += -1;
            } else {
                pre_sum += nums[i];  // nums[i] is 1
            }

            // If this prefix sum was seen before,
            // the subarray between the two indices has equal 0s and 1s
            if (pre_count.find(pre_sum) != pre_count.end()) {
                count = i - pre_count[pre_sum];
                max_count = max(count, max_count);
            } 
            // Store the first occurrence of this prefix sum
            else {
                pre_count[pre_sum] = i;
            }
        }
        return max_count;
    }
};
