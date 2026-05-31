/*
 * LeetCode 35 - Search Insert Position
 * Approach: Binary Search
 *
 * Description:
 * Search for the target in a sorted array.
 * If found, return its index.
 * Otherwise, return the position where it should be inserted
 * to maintain sorted order.
 *
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start = 0, end = static_cast<int>(nums.size()) - 1;

        while (start <= end) {

            // Find middle index safely
            int mid = start + (end - start) / 2;

            // Target found
            if (nums[mid] == target)
                return mid;

            // Search in right half
            if (nums[mid] < target)
                start = mid + 1;

            // Search in left half
            else
                end = mid - 1;
        }

        // start points to the correct insertion position
        return start;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1, 3, 5, 6};
    cout << "Test 1: " << sol.searchInsert(nums1, 5) << endl; // Expected: 2

    vector<int> nums2 = {1, 3, 5, 6};
    cout << "Test 2: " << sol.searchInsert(nums2, 2) << endl; // Expected: 1

    return 0;
}