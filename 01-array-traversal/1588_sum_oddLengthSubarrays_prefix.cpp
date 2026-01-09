#include <vector>
#include <iostream>
using namespace std;
// Problem: 1588. Sum of All Odd Length Subarrays
// Approach: Prefix Sum
// Time Complexity: O(n^2)
// Space Complexity: O(n)
//
// Improves over brute-force O(n^3) using prefix sums.
// Note: Optimal O(n) time, O(1) space solution exists using combinatorics.

class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {

        // Length of the array
        int len = arr.size();

        // Prefix sum array where:
        // prefix_sum[i] = sum of elements from index 0 to i-1
        vector<int> prefix_sum(len + 1);
        prefix_sum[0] = 0;

        // Build the prefix sum array
        for (int i = 1; i <= len; i++) {
            prefix_sum[i] = prefix_sum[i - 1] + arr[i - 1];
        }

        // Initial sum contains sum of all odd subarrays of length 1
        // (i.e., sum of all individual elements)
        int sum = prefix_sum[len];

        int off = 0;

        // Loop through each starting index
        for (int i = 0; i < len; i++) {

            // Start with subarray length = 3 (next odd length)
            off = 3;

            // Generate odd-length subarrays starting at index i
            while (i + off <= len) {

                // If starting index is 0, prefix_sum[i] is 0
                if (i == 0) {
                    sum += prefix_sum[i + off];
                }
                // General case: sum of subarray = prefix_sum[end] - prefix_sum[start]
                else {
                    sum += prefix_sum[i + off] - prefix_sum[i];
                }

                // Move to the next odd length
                off += 2;
            }
        }

        // Final sum of all odd-length subarrays
        return sum;
    }
};
