#include <vector>
#include <unordered_map>
using namespace std;

// Approach 4: Prefix Sum + HashMap (Optimal)
// Idea:
// Store how many times each prefix sum has appeared so far.
// If (left_sum - k) exists in the map, it means there are
// that many subarrays ending at the current index with sum = k.
//
// Why this works:
// sum(i..j) = prefix[j] - prefix[i-1]
// So if prefix[j] - k was seen before, a valid subarray exists.
//
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int c = 0, n = nums.size();
        int left_sum = 0;

        unordered_map<int, int> prefix_count;

        // Base case: prefix sum 0 occurs once
        prefix_count[0] = 1;

        for (int num : nums) {
            left_sum += num;

            int target = left_sum - k;

            // If target prefix sum exists, add its frequency
            if (prefix_count.find(target) != prefix_count.end()) {
                c += prefix_count[target];
            }

            // Record current prefix sum
            prefix_count[left_sum]++;
        }

        return c;
    }
};
