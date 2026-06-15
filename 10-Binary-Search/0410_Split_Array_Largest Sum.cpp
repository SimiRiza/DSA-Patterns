/*
 * LeetCode 410 - Split Array Largest Sum
 * Approach: Binary Search on Answer
 *
 * We binary search the maximum allowed subarray sum (capacity).
 * For a given capacity, greedily form partitions and count how many
 * are needed. If the number of partitions is <= k, the capacity is feasible.
 *
 * Time Complexity: O(n * log(sum(nums)))
 * Space Complexity: O(1)
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Check whether the array can be split into at most k parts
    // such that no part has sum greater than capacity.
    bool check_possible(vector<int>& nums, int k, int capacity) {
        int curr_sum = 0;
        int parts = 0;

        for (int i = 0; i < (int)nums.size(); i++) {

            // Current element fits in the current partition
            if (curr_sum + nums[i] <= capacity) {
                curr_sum += nums[i];
            }
            else {
                // Start a new partition with nums[i]
                parts++;
                curr_sum = nums[i];
            }
        }

        // Count the final partition
        if (curr_sum <= capacity)
            parts++;

        return parts <= k;
    }

    int splitArray(vector<int>& nums, int k) {

        // Lower bound = largest element
        // Upper bound = sum of all elements
        int mx = nums[0];
        int sum = 0;

        for (int x : nums) {
            mx = max(mx, x);
            sum += x;
        }

        int start = mx;
        int end = sum;

        while (start <= end) {

            int mid = start + (end - start) / 2;

            // If feasible, try a smaller answer
            if (check_possible(nums, k, mid)) {
                end = mid - 1;
            }
            else {
                // Need a larger capacity
                start = mid + 1;
            }
        }

        return start;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {7, 2, 5, 10, 8};
    cout << sol.splitArray(nums1, 2) << endl; // Expected: 18

    vector<int> nums2 = {1, 2, 3, 4, 5};
    cout << sol.splitArray(nums2, 2) << endl; // Expected: 9

    return 0;
}