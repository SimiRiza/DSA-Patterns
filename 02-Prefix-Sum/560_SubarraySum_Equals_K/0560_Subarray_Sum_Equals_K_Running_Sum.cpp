#include <vector>
using namespace std;

// Approach 3: Running Sum (Optimized Nested Loops)
// Idea:
// Fix a starting index and keep adding elements while expanding the end index.
// Avoid recomputing sums repeatedly.
//
// Time Complexity: O(n^2)
// Space Complexity: O(1)

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int c = 0, n = nums.size(), sum;

        for (int s = 0; s < n; s++) {
            sum = 0;
            for (int e = s; e < n; e++) {
                sum += nums[e];
                if (sum == k) c++;
            }
        }
        return c;
    }
};
