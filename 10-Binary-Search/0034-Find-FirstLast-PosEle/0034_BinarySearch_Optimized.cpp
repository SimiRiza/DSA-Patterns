/*
Approach: Two Boundary Binary Searches (Optimal)

Description:
1. Perform Binary Search to find the first occurrence.
2. Perform Binary Search to find the last occurrence.
3. Return both indices.

Time Complexity: O(log n)
Space Complexity: O(1)

Self Note:
This is the interview-preferred solution.

Instead of first finding any occurrence and then searching
for boundaries, we directly search for:

1. First occurrence
2. Last occurrence

Cleaner logic, easier explanation, and optimal complexity.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = -1;
        int last = -1;

        int start;
        int end;
        int mid;

        // Find first occurrence
        start = 0;
        end = nums.size() - 1;

        while (start <= end) {
            mid = start + (end - start) / 2;

            if (nums[mid] == target) {
                first = mid;
                end = mid - 1;
            }
            else if (nums[mid] < target) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }

        // Find last occurrence
        start = 0;
        end = nums.size() - 1;

        while (start <= end) {
            mid = start + (end - start) / 2;

            if (nums[mid] == target) {
                last = mid;
                start = mid + 1;
            }
            else if (nums[mid] < target) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }

        return {first, last};
    }
};

int main() {
    Solution sol;

    vector<int> nums = {5, 7, 7, 8, 8, 10};

    vector<int> ans = sol.searchRange(nums, 8);

    cout << "[" << ans[0] << ", " << ans[1] << "]\n";

    return 0;
}