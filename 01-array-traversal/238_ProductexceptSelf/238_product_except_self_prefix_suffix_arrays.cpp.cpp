#include <vector>
#include <iostream>
using namespace std;

// LeetCode 238: Product of Array Except Self
// Approach: Use prefix (left) and suffix (right) product arrays
// Time Complexity: O(n)
// Space Complexity: O(n) extra space (two auxiliary arrays)

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        vector<int> left(nums.size());   // left[i] = product of elements before i
        vector<int> right(nums.size());  // right[i] = product of elements after i

        // No elements to the left of index 0
        left[0] = 1;

        // No elements to the right of last index
        right[nums.size() - 1] = 1;

        // Build prefix and suffix products simultaneously
        for (int i = 1, j = nums.size() - 2; i < nums.size(); i++, j--) {
            left[i] = left[i - 1] * nums[i - 1];      // prefix product
            right[j] = right[j + 1] * nums[j + 1];    // suffix product
        }

        // Final result: multiply left and right products
        for (int i = 0; i < nums.size(); i++) {
            nums[i] = left[i] * right[i];
        }

        return nums;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 4};
    vector<int> result = sol.productExceptSelf(nums);
    for (int x : result) {
        cout << x << " ";
    }
    return 0;
}

