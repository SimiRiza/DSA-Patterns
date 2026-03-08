/*
Approach: Two Pointer Scan

nums1 and nums2 are non-increasing arrays.
We move pointer j in nums2 as far as possible while nums1[i] <= nums2[j].
Distance = j - i.
Track the maximum distance.

Time Complexity: O(n + m)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int j = 0, res = 0;

        for (int i = 0; i < nums1.size(); i++) {

            while (j < nums2.size() && nums1[i] <= nums2[j]) {
                j++;
            }

            if (j != 0)
                j--;

            res = max(res, j - i);
        }

        return res;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {55,30,5,4,2};
    vector<int> nums2 = {100,20,10,10,5};
    cout << sol.maxDistance(nums1, nums2) << endl;  // Expected: 2

    vector<int> nums1b = {2,2,2};
    vector<int> nums2b = {10,10,1};
    cout << sol.maxDistance(nums1b, nums2b) << endl; // Expected: 1

    return 0;
}