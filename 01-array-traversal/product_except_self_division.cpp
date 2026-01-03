#include <vector>
using namespace std;
// LeetCode: Product of Array Except Self
// Approach: Compute product of non-zero elements and count zeros.
// Handle cases based on number of zeros.
// Time: O(n), Space: O(1)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int zero_count = 0;   // counts how many zeros are present in the array
        int mul = 1;          // stores product of all non-zero elements

        // First pass: calculate product of non-zero elements
        // and count number of zeros
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                zero_count++;
            } else {
                mul = mul * nums[i];
            }
        }

        // Second pass: build the result based on zero count
        for (int i = 0; i < nums.size(); i++) {

            // Case 1: Exactly one zero in array
            // Only the position with zero gets the product
            if (zero_count == 1) {
                if (nums[i] == 0)
                    nums[i] = mul;
                else
                    nums[i] = 0;
            }

            // Case 2: More than one zero
            // All products will be zero
            else if (zero_count > 1) {
                nums[i] = 0;
            }

            // Case 3: No zeros
            // Safe to use division
            else {
                nums[i] = mul / nums[i];
            }
        }

        return nums;
    }
};
