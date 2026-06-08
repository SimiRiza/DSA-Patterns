/*
 * LeetCode 162 - Find Peak Element
 * Approach: Binary Search Invariant
 *
 * Idea:
 * - Maintain a search range that is guaranteed to contain a peak.
 * - If nums[mid] < nums[mid + 1], we are on an increasing slope,
 *   so a peak must exist on the right side.
 * - Otherwise, a peak exists at mid or on the left side.
 * - Shrink the range until only one index remains.
 *
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;

        while (start < end) {
            int mid = start + (end - start) / 2;

            // Increasing slope -> peak exists on the right side
            if (nums[mid] < nums[mid + 1]) {
                start = mid + 1;
            }
            // Decreasing slope -> peak exists at mid or on the left side
            else {
                end = mid;
            }
        }

        // Only one candidate remains
        return start;
    }
};

int main() {
    Solution sol;

    vector<int> test1 = {1, 2, 3, 1};
    cout << "Peak Index: " << sol.findPeakElement(test1) << endl;

    vector<int> test2 = {1, 2, 1, 3, 5, 6, 4};
    cout << "Peak Index: " << sol.findPeakElement(test2) << endl;

    return 0;
}