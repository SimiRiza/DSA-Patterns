/*
Approach: Sorting + Sliding Window

Description:
We sort the scores so close values become adjacent.
Then we slide a window of size k across the array.
For each window, the minimum element is nums[start]
and the maximum element is nums[end].

Difference = nums[end] - nums[start]

We track the minimum difference among all such windows.

Time Complexity: O(n log n)
    Sorting dominates.

Space Complexity: O(1)
    Only variables used.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int st = 0, end = k - 1, minimum = INT_MAX;

        if (nums.size() == 1 || k == 1) {
            return 0;
        }

        while (end < nums.size()) {
            minimum = min(minimum, nums[end] - nums[st]);
            end++;
            st++;
        }

        return minimum;
    }
};

int main() {
    Solution sol;

    // Test 1
    vector<int> nums1 = {9,4,1,7};
    cout << "Test1 Output: " << sol.minimumDifference(nums1, 2) << endl;

    // Test 2
    vector<int> nums2 = {87063,61094,44530,21297,95857,93551,9918};
    cout << "Test2 Output: " << sol.minimumDifference(nums2, 6) << endl;

    return 0;
}