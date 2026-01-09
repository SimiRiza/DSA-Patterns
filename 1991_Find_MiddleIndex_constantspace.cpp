#include <vector>
using namespace std;
// 1991_Find_Middle_Index.cpp
// LeetCode 1991: Find the Middle Index in Array
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int sum = 0;
        // Step 1: Calculate total sum of the array
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        int left_sum = 0;
        // Step 2: Traverse and check middle index
        for (int i = 0; i < nums.size(); i++) {
            // Right sum = total sum - left sum - current element
            int right_sum = sum - left_sum - nums[i];
            // If left sum equals right sum, we found the middle index
            if (left_sum == right_sum)
                return i;
            // Update left sum for next index
            left_sum += nums[i];
        }
        // No middle index found
        return -1;
    }
};
