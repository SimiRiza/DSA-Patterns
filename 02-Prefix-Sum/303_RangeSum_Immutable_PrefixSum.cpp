#include <vector>
using namespace std;
// LeetCode 303 - Range Sum Query - Immutable
// Approach: Prefix Sum
// Time Complexity:
//   - Constructor: O(n)
//   - sumRange: O(1)
// Space Complexity: O(n)

class NumArray {
public:
    vector<int> pre;  // prefix sum array

    // Constructor builds the prefix sum array
    NumArray(vector<int>& nums) {
        pre.resize(nums.size());      // allocate space first

        pre[0] = nums[0];             // first element
        for (int i = 1; i < nums.size(); i++) {
            pre[i] = pre[i - 1] + nums[i];  // cumulative sum
        }
    }

    // Returns sum of elements from index left to right (inclusive)
    int sumRange(int left, int right) {
        // if range starts from index 0
        if (left == 0)
            return pre[right];

        // otherwise subtract prefix before left
        return pre[right] - pre[left - 1];
    }
};
