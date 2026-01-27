#include <vector>
using namespace std;

/*
Approach:
- Use three pointers:
  i -> last valid element in nums1
  j -> last element in nums2
  k -> last position in nums1

- Merge from the back.
- When values are equal, place both elements at once.
- After one array is exhausted, copy remaining elements.

Time Complexity: O(m + n)
Space Complexity: O(1)
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else if (nums1[i] < nums2[j]) {
                nums1[k--] = nums2[j--];
            } else {
                nums1[k] = nums2[j];
                nums1[k - 1] = nums1[i];
                k -= 2;
                i--;
                j--;
            }
        }

        // Copy remaining elements from nums2 if any
        while (j >= 0) {
            nums1[k--] = nums2[j--];
        }
    }
};
