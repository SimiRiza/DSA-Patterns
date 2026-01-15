#include <vector>
using namespace std;

// LeetCode 1524: Number of Sub-arrays With Odd Sum
// Approach: Prefix Sum + Counting (Parity based)
// Time Complexity: O(n)
// Space Complexity: O(1)
//
// Idea:
// - Track parity (odd/even) of prefix sums
// - Odd subarray sum happens when:
//   1) current prefix is odd  + previous even prefix
//   2) current prefix is even + previous odd prefix

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;

        long long left_sum = 0;   // running prefix sum
        long long even_c = 0;     // count of even prefix sums seen so far
        long long odd_c = 0;      // count of odd prefix sums seen so far
        long long count = 0;      // total odd-sum subarrays

        for (int num : arr) {
            left_sum += num;

            // If current prefix sum is odd
            if (left_sum % 2 != 0) {
                // Subarray starting from index 0
                count = (count + 1) % MOD;

                // Pair current odd prefix with all previous even prefixes
                count = (count + even_c) % MOD;

                // Mark this prefix as odd
                odd_c++;
            }
            // If current prefix sum is even
            else {
                // Pair current even prefix with all previous odd prefixes
                count = (count + odd_c) % MOD;

                // Mark this prefix as even
                even_c++;
            }
        }

        return count;
    }
};
