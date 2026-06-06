/*
Approach: Binary Search + Boundary Binary Searches

Description:
1. Find any occurrence of target using Binary Search.
2. Search left half using Binary Search to find first occurrence.
3. Search right half using Binary Search to find last occurrence.
4. Return both boundaries.

Time Complexity: O(log n)
Space Complexity: O(1)

Self Note:
This improves upon linear expansion by using Binary Search
to locate both boundaries.

Although optimal, it performs an additional Binary Search
to locate an initial occurrence before finding boundaries.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result;

        int start = 0;
        int end = nums.size() - 1;
        int mid;
        int idx = -1;
        bool found = false;

        // Find any occurrence of target
        while (start <= end) {
            mid = start + (end - start) / 2;

            if (nums[mid] < target)
                start = mid + 1;
            else if (nums[mid] > target)
                end = mid - 1;
            else {
                idx = mid;
                found = true;
                break;
            }
        }

        if (found) {
            int left_idx = idx;

            int s = start;
            int e = idx - 1;

            // Find leftmost occurrence
            while (s <= e) {
                mid = s + (e - s) / 2;

                if (nums[mid] < target)
                    s = mid + 1;
                else if (nums[mid] > target)
                    e = mid - 1;
                else {
                    left_idx = min(left_idx, mid);
                    e = mid - 1;
                }
            }

            int right_idx = idx;

            s = idx + 1;
            e = end;

            // Find rightmost occurrence
            while (s <= e) {
                mid = s + (e - s) / 2;

                if (nums[mid] < target)
                    s = mid + 1;
                else if (nums[mid] > target)
                    e = mid - 1;
                else {
                    right_idx = max(right_idx, mid);
                    s = mid + 1;
                }
            }

            result = {left_idx, right_idx};
        }
        else {
            result = {-1, -1};
        }

        return result;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {5, 7, 7, 8, 8, 10};

    vector<int> ans = sol.searchRange(nums, 8);

    cout << "[" << ans[0] << ", " << ans[1] << "]\n";

    return 0;
}