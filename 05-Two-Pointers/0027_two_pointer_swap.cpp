/*
Approach: Two Pointer Swap (Unordered Removal)

Idea:
We keep two pointers:
- curr → scans from the start
- rep  → points to the last valid position

If nums[curr] == val:
    swap it with nums[rep] (if rep is not val)
    shrink rep
Else:
    move curr forward

This works because order does NOT matter for this problem.

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int curr = 0;
        int rep = nums.size() - 1;

        while (curr <= rep) {
            if (nums[curr] == val) {
                if (nums[rep] != val) {
                    swap(nums[curr], nums[rep]);
                    rep--;
                    curr++;
                } 
                else {
                    rep--;
                }
            } 
            else {
                curr++;
            }
        }

        return rep + 1;
    }
};

int main() {
    Solution s;

    vector<int> nums1 = {3,2,2,3};
    int k1 = s.removeElement(nums1, 3);
    cout << "k = " << k1 << endl;

    vector<int> nums2 = {0,1,2,2,3,0,4,2};
    int k2 = s.removeElement(nums2, 2);
    cout << "k = " << k2 << endl;

    return 0;
}
