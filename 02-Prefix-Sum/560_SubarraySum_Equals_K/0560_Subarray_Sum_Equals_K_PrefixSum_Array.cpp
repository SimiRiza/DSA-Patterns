#include <vector>
using namespace std;

// Approach 2: Prefix Sum Array
// Idea:
// Precompute prefix sums so that sum of any subarray can be found in O(1).
// sum(s..e) = prefix[e] - prefix[s-1]
//
// Time Complexity: O(n^2)
// Space Complexity: O(n)

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int c = 0, n = nums.size();
        vector<int> prefix_sum(n);

        prefix_sum[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefix_sum[i] = prefix_sum[i - 1] + nums[i];
        }

        for (int s = 0; s < n; s++) {
            for (int e = s; e < n; e++) {
                int sum = prefix_sum[e] - (s == 0 ? 0 : prefix_sum[s - 1]);
                if (sum == k) c++;
            }
        }
        return c;
    }
};
