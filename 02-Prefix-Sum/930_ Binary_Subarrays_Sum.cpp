#include <vector>
#include <unordered_map>
using namespace std;

// Problem: Count Number of Subarrays With Sum Equal to Goal
// Approach: Prefix Sum + HashMap
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int prefix_sum = 0;     // Stores cumulative sum till current index
        int c = 0;              // Stores total count of valid subarrays
        int target;             // prefix_sum - goal

        unordered_map<int, int> prefix_count;
        // prefix_count[x] = number of times prefix sum 'x' has occurred

        // Base case:
        // A prefix sum of 0 occurs once before starting the array
        prefix_count[0] = 1;

        for (int num : nums) {
            prefix_sum += num;  // Update prefix sum

            // We want: current_prefix_sum - previous_prefix_sum = goal
            // So previous_prefix_sum = prefix_sum - goal
            target = prefix_sum - goal;

            // If such a prefix sum exists, add its frequency
            if (prefix_count.find(target) != prefix_count.end()) {
                c += prefix_count[target];
            }

            // Store/update frequency of current prefix sum
            prefix_count[prefix_sum]++;
        }

        return c;
    }
};
