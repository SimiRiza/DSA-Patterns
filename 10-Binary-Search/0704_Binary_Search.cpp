/*
 * LeetCode 704 - Binary Search
 * Approach: Classic Binary Search
 *
 * Description:
 * Search for the target in a sorted array by repeatedly
 * halving the search space.
 *
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0;
        int end = static_cast<int>(nums.size()) - 1;

        while (start <= end) {

            // Calculate middle index
            int tar_idx = start + (end - start) / 2;

            // Target found
            if (nums[tar_idx] == target)
                return tar_idx;

            // Search right half
            else if (nums[tar_idx] < target)
                start = tar_idx + 1;

            // Search left half
            else
                end = tar_idx - 1;
        }

        // Target not found
        return -1;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {-1, 0, 3, 5, 9, 12};
    cout << "Test 1: " << sol.search(nums1, 9) << endl;   // Expected: 4

    vector<int> nums2 = {-1, 0, 3, 5, 9, 12};
    cout << "Test 2: " << sol.search(nums2, 2) << endl;   // Expected: -1

    return 0;
}