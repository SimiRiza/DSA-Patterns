#include <vector>
using namespace std;

// File: running_sum.cpp
// Problem: Running Sum of 1D Array
// Approach: Prefix sum (in-place)

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        // Start from index 1 because the first element
        // is already the running sum of itself
        for (int i = 1; i < nums.size(); i++) {
            // Add previous sum to current element
            nums[i] += nums[i - 1];
        }

        // Return the modified array
        return nums;
    }
};
