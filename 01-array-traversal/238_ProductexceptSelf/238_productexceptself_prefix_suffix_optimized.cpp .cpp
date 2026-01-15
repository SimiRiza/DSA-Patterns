#include <vector>
#include<iostream>
using namespace std;

// LeetCode: Product of Array Except Self
// Approach: Prefix product stored in result array,
// then multiplied by a running suffix (right) product.
// Time: O(n), Extra Space: O(1) (excluding output array)

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        vector<int> res(nums.size());   // result array
        res[0] = 1;                     // no elements on the left of index 0

        // First pass: build prefix products
        // res[i] = product of all elements to the left of i
        for (int i = 1; i < nums.size(); i++) {
            res[i] = res[i - 1] * nums[i - 1];
        }

        // Initialize right product with last element
        int ryt_pro = nums[nums.size() - 1];

        // Second pass: multiply prefix products with suffix products
        for (int j = nums.size() - 2; j >= 0; j--) {
            res[j] = res[j] * ryt_pro;  // multiply left and right products
            ryt_pro = ryt_pro * nums[j]; // update right product
        }

        return res;
    }
};
// Example usage
int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 4};

    vector<int> result = sol.productExceptSelf(nums);

    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}
