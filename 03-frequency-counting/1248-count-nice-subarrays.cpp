#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
Approach:
- Treat each odd number as 1, even as 0
- Use prefix sum to track number of odds so far
- If (prefix_sum - k) exists in map, it forms valid subarrays

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> pre_count;
        int pre_sum = 0, count = 0;

        // Base case: prefix sum 0 occurs once
        pre_count[0] = 1;

        for (int num : nums) {
            if (num % 2 != 0) {
                pre_sum++;  // count odd numbers
            }

            int target = pre_sum - k;

            if (pre_count.find(target) != pre_count.end()) {
                count += pre_count[target];
            }

            pre_count[pre_sum]++;
        }

        return count;
    }
};

// Sample test cases
int main() {
    Solution sol;

    vector<int> nums1 = {1, 1, 2, 1, 1};
    cout << sol.numberOfSubarrays(nums1, 3) << endl; // Expected: 2

    vector<int> nums2 = {2, 4, 6};
    cout << sol.numberOfSubarrays(nums2, 1) << endl; // Expected: 0

    vector<int> nums3 = {2, 2, 2, 1, 2, 2, 1, 2, 2, 2};
    cout << sol.numberOfSubarrays(nums3, 2) << endl; // Expected: 16

    return 0;
}
