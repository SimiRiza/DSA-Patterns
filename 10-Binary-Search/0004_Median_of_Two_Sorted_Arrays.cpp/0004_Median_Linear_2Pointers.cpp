/*
 * Approach: Merge Traversal (Without Extra Array)
 *
 * Description:
 * Traverse both sorted arrays similarly to the merge step of Merge Sort.
 * Track only the elements at the median indices instead of constructing
 * the entire merged array. This achieves O(1) extra space.
 *
 * Time Complexity: O(m + n)
 * Space Complexity: O(1)
 */

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int count = 0;
        int n1 = nums1.size(), n2 = nums2.size();
        int n = n1 + n2;

        int idx1 = n / 2 - 1;
        int idx2 = n / 2;

        int ele1 = 0, ele2 = 0;
        int nums1_ptr = 0, nums2_ptr = 0;

        // Merge traversal while both arrays have elements
        while (nums1_ptr < n1 && nums2_ptr < n2) {
            if (nums1[nums1_ptr] <= nums2[nums2_ptr]) {

                // Store median candidates when required indices are reached
                if (count == idx1) {
                    ele1 = nums1[nums1_ptr];
                }
                else if (count == idx2) {
                    ele2 = nums1[nums1_ptr];
                }

                count++;
                nums1_ptr++;
            }
            else {

                // Store median candidates when required indices are reached
                if (count == idx1) {
                    ele1 = nums2[nums2_ptr];
                }
                else if (count == idx2) {
                    ele2 = nums2[nums2_ptr];
                }

                nums2_ptr++;
                count++;
            }
        }

        // Process remaining elements from nums1
        if (nums2_ptr == n2) {
            while (nums1_ptr < n1) {

                if (count == idx1) {
                    ele1 = nums1[nums1_ptr];
                }
                else if (count == idx2) {
                    ele2 = nums1[nums1_ptr];
                }

                nums1_ptr++;
                count++;
            }
        }

        // Process remaining elements from nums2
        else if (nums1_ptr == n1) {
            while (nums2_ptr < n2) {

                if (count == idx1) {
                    ele1 = nums2[nums2_ptr];
                }
                else if (count == idx2) {
                    ele2 = nums2[nums2_ptr];
                }

                nums2_ptr++;
                count++;
            }
        }

        // Return median based on total length parity
        if (n % 2 == 0) {
            return (double)(ele1 + ele2) / 2;
        }

        return ele2;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    cout << "Test 1: " << sol.findMedianSortedArrays(nums1, nums2) << endl;

    vector<int> nums3 = {1, 2};
    vector<int> nums4 = {3, 4};
    cout << "Test 2: " << sol.findMedianSortedArrays(nums3, nums4) << endl;

    return 0;
}