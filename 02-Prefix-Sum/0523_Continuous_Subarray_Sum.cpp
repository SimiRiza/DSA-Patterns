#include <bits/stdc++.h>
using namespace std;

/*
Key Idea:
- Use prefix sum and modulo arithmetic.
- If two prefix sums have the same remainder when divided by k,
  their difference is a multiple of k.
- Store the first occurrence of each remainder in a hashmap.
- Also ensure the subarray length is at least 2.

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {

        // Map: remainder -> earliest index
        unordered_map<int,int> rem_idx;

        // Handles subarrays starting from index 0
        rem_idx[0] = -1;

        long long left_sum = 0;
        int rem;

        for (int i = 0; i < nums.size(); i++) {

            // Update prefix sum
            left_sum += nums[i];

            // Compute remainder
            rem = left_sum % k;

            // If remainder seen before
            if (rem_idx.find(rem) != rem_idx.end()) {

                // Check subarray length >= 2
                if (i - rem_idx[rem] >= 2) {
                    return true;
                }
            }
            else {
                // Store first occurrence of remainder
                rem_idx[rem] = i;
            }
        }

        return false;
    }
};
