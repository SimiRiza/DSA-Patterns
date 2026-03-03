/*
-----------------------------------------
LeetCode 75 - Sort Colors
Approach: Dutch National Flag Algorithm

Description:
Uses three pointers (curr, one_start, two_start) to partition
the array into 0s, 1s, and 2s in a single pass.
- 0s are moved to the front
- 2s are moved to the back
- 1s stay in the middle

Time Complexity: O(n)
Space Complexity: O(1)
-----------------------------------------
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int curr = 0, one_start = 0, two_start = nums.size() - 1;

        while (curr <= two_start) {
            if (nums[curr] == 0) {
                swap(nums[one_start], nums[curr]);
                curr++;
                one_start++;
            }
            else if (nums[curr] == 1) {
                curr++;
            }
            else {
                swap(nums[two_start], nums[curr]);
                two_start--;
            }
        }
    }
};

int main() {
    Solution sol;

    vector<int> test1 = {2,0,2,1,1,0};
    sol.sortColors(test1);
    for (int x : test1) cout << x << " ";
    cout << endl;

    vector<int> test2 = {2,0,1};
    sol.sortColors(test2);
    for (int x : test2) cout << x << " ";
    cout << endl;

    return 0;
}