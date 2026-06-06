/*
Approach: Binary Search + Linear Expansion

Description:
1. Use Binary Search to find any occurrence of target.
2. Expand left while elements are equal to target.
3. Expand right while elements are equal to target.
4. Return the first and last positions found.

Time Complexity:
- Best/Average: O(log n)
- Worst Case: O(n)

Space Complexity: O(1)

Self Note:
After finding one occurrence, we linearly expand in both directions.
If most elements are the target, the expansion may scan almost the
entire array, making the worst-case complexity O(n).
*/

#include <iostream>
#include <vector>

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
            int i = idx;

            // Expand towards left boundary
            while (i != -1 && nums[i] == nums[idx]) {
                i--;
            }
            result.push_back(i + 1);

            i = idx;

            // Expand towards right boundary
            while (i != nums.size() && nums[i] == nums[idx]) {
                i++;
            }
            result.push_back(i - 1);
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