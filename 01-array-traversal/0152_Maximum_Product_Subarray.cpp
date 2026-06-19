/*
LeetCode 152 - Maximum Product Subarray

Approach:
Maintain the maximum and minimum product ending at each index.
When a negative number is encountered, max and min can swap roles.

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int currMax = nums[0];
        int currMin = nums[0];
        int ans = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < 0) {
                swap(currMax, currMin);
            }

            currMax = max(nums[i], currMax * nums[i]);
            currMin = min(nums[i], currMin * nums[i]);

            ans = max(ans, currMax);
        }

        return ans;
    }
};

int main() {
    Solution obj;

    vector<int> nums = {2, 3, -2, 4};

    cout << "Maximum Product Subarray: "
         << obj.maxProduct(nums) << endl;

    return 0;
}