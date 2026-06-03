/*
 * LeetCode 153 - Find Minimum in Rotated Sorted Array
 * Approach: Binary Search on Sorted Half
 *
 * Idea:
 * - At every step, one half of the array is guaranteed to be sorted.
 * - If the current search range is already sorted, the first element
 *   of that range is the minimum.
 * - For a sorted half, its minimum is its leftmost element.
 * - Record the candidate minimum and continue searching only in the
 *   unsorted half where the rotation pivot may exist.
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
        int s = 0;
        int e = static_cast<int>(nums.size()) - 1;

        // Initialize answer with the first element
        int ans = nums[0];

        while (s <= e) {

            // If the current range is fully sorted,
            // the leftmost element is the minimum.
            if (nums[s] <= nums[e]) {
                ans = min(ans, nums[s]);
                break;
            }

            int mid = s + (e - s) / 2;

            // Left half is sorted
            if (nums[s] <= nums[mid]) {
                ans = min(ans, nums[s]); // Minimum of sorted left half
                s = mid + 1;             // Search unsorted right half
            }
            // Right half is involved with rotation
            else {
                ans = min(ans, nums[mid]); // Potential minimum candidate
                e = mid - 1;               // Search left side
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> test1 = {3, 4, 5, 1, 2};
    cout << "Test 1: " << sol.findMin(test1) << endl; // Expected: 1

    vector<int> test2 = {4, 5, 6, 7, 0, 1, 2};
    cout << "Test 2: " << sol.findMin(test2) << endl; // Expected: 0

    return 0;
}