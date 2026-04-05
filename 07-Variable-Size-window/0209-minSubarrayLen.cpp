// LC 209 - Minimum Size Subarray Sum
// Approach: Sliding Window
// Idea: Expand window (right), and shrink (left) when sum >= target

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, right = 0;
        int n = nums.size();
        int min_len = INT_MAX;        // stores best (minimum) length found
        long long sum = 0;     

        while (right < n) {
            sum += nums[right];       // expand window by including nums[right]

            // shrink window while condition is satisfied
            while (sum >= target && left < n) {
                int curr_len = right - left + 1;   // current window size
                min_len = min(min_len, curr_len);  // update answer

                sum -= nums[left];   // remove left element
                left++;              // shrink window from left
            }

            right++;              
        }

        // if no valid subarray found, return 0
        return min_len == INT_MAX ? 0 : min_len;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {2,3,1,2,4,3};
    cout << sol.minSubArrayLen(7, nums1) << endl; // Expected: 2

    vector<int> nums2 = {1,1,1,1,1,1,1,1};
    cout << sol.minSubArrayLen(11, nums2) << endl; // Expected: 0

    return 0;
}