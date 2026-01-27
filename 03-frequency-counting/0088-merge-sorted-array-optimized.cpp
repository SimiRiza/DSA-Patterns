#include <vector>
using namespace std;

/*
Optimized Approach (Canonical Solution):
- Merge from the back using three pointers.
- Always place exactly ONE element per iteration.
- No special handling for equal values needed.

Time Complexity: O(m + n)
Space Complexity: O(1)
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        while (j >= 0) {
            if (i >= 0 && nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }
    }
};
