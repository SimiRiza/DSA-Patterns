/*
-----------------------------------------
LeetCode 905 - Sort Array By Parity
Approach: Two Pointer Partitioning

Description:
Uses two pointers:
- curr scans from left
- odd_ptr tracks position to place odd numbers at the end

If current element is odd, swap it to the back.
If even, move forward.
-----------------------------------------
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int curr = 0, odd_ptr = nums.size() - 1;

        while (curr <= odd_ptr) {
            if (nums[curr] % 2 != 0) {
                swap(nums[curr], nums[odd_ptr]);
                odd_ptr--;   // shrink right boundary
            }
            else {
                curr++;      // move forward if even
            }
        }
        return nums;
    }
};

int main() {
    Solution sol;

    vector<int> test1 = {3,1,2,4};
    vector<int> res1 = sol.sortArrayByParity(test1);
    for (int x : res1) cout << x << " ";
    cout << endl;

    vector<int> test2 = {0};
    vector<int> res2 = sol.sortArrayByParity(test2);
    for (int x : res2) cout << x << " ";
    cout << endl;

    return 0;
}