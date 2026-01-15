#include <vector>
using namespace std;

// Approach 1: Brute Force (3 loops)
// Idea:
// Generate every possible subarray and calculate its sum explicitly.
// If the sum equals k, increase the count.
//
// Time Complexity: O(n^3)
// Space Complexity: O(1)

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int c = 0, n = nums.size(), sum = 0;

        for (int s = 0; s < n; s++) {
            for (int e = s; e < n; e++) {
                sum = 0;
                for (int curr = s; curr <= e; curr++) {
                    sum += nums[curr];
                }
                if (sum == k) c++;
            }
        }
        return c;
    }
};
