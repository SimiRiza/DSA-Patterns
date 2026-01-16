#include <bits/stdc++.h>
using namespace std;

/*
Key Idea:
- Use prefix sum and modulo arithmetic.
- If two prefix sums have the same remainder when divided by k,
  their difference is divisible by k.
- Count how many times each remainder appears using a hashmap.

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {

        // Map: remainder -> frequency count
        unordered_map<int, int> remainder_count;

        // Prefix sum remainder 0 occurs once initially
        remainder_count[0] = 1;

        int count = 0;
        long long prefix_sum = 0;

        for (int i = 0; i < nums.size(); ++i) {

            // Update prefix sum
            prefix_sum += nums[i];

            // Compute remainder
            int rem = prefix_sum % k;

            // Handle negative remainder case
            if (rem < 0) rem += k;

            // If remainder seen before, add its frequency
            if (remainder_count.find(rem) != remainder_count.end()) {
                count += remainder_count[rem];
            }

            // Increment frequency of current remainder
            remainder_count[rem]++;
        }

        return count;
    }
};
