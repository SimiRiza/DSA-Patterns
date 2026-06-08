/*
 * LeetCode 162 - Find Peak Element
 * Approach: Explicit Peak Validation
 *
 * Idea:
 * - Use binary search to locate a candidate region.
 * - If the next element is larger, move right.
 * - If the next element is smaller, check whether the
 *   current element is a valid peak.
 * - Return immediately when a peak is found.
 *
 * Note:
 * - This follows the original intuition of explicitly
 *   verifying peak conditions.
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
        int mid;

        while (start <= end) {
            mid = start + (end - start) / 2;

            // Moving uphill, peak must be on the right
            if (mid < nums.size() - 1 && nums[mid + 1] > nums[mid]) {
                start = mid + 1;
            }
            // Moving downhill
            else if (mid < nums.size() - 1 && nums[mid + 1] < nums[mid]) {

                // Explicit peak validation
                if (mid > 0 && nums[mid - 1] < nums[mid]) {
                    return mid;
                } else {
                    end = mid - 1;
                }
            }
            else {
                break;
            }
        }

        return mid;
    }
};

int main() {
    Solution sol;

    vector<int> test1 = {1, 2, 3, 1};
    cout << "Peak Index: " << sol.findPeakElement(test1) << endl;

    vector<int> test2 = {3, 2, 1};
    cout << "Peak Index: " << sol.findPeakElement(test2) << endl;

    return 0;
}