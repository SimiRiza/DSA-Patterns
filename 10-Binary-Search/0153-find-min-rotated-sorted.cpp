/*
 * LeetCode 153 - Find Minimum in Rotated Sorted Array
 * Approach: Binary Search on Sorted Half
 *
 * Idea:
 * - At every step, one half is guaranteed to be sorted.
 * - If left half is sorted, the minimum could be nums[start]
 *   or may exist in the right half.
 * - Otherwise, pivot/minimum lies in the left half including mid.
 *
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0, end = nums.size() - 1;
        int ans = nums[0], mid;

        while (start <= end) {
            mid = start + (end - start) / 2;

            // Left half is sorted
            if (nums[start] <= nums[mid]) {
                ans = min(ans, nums[start]);

                // Search in right half
                start = mid + 1;
            }
            else {
                // Minimum may be at mid or left side
                ans = min(ans, nums[mid]);

                // Search in left half
                end = mid - 1;
            }
        }

        return ans;
    }
};

int main() {
    Solution obj;

    vector<int> test1 = {3, 4, 5, 1, 2};
    cout << "Test 1: " << obj.findMin(test1) << endl; // Expected: 1

    vector<int> test2 = {4, 5, 6, 7, 0, 1, 2};
    cout << "Test 2: " << obj.findMin(test2) << endl; // Expected: 0

    return 0;
}