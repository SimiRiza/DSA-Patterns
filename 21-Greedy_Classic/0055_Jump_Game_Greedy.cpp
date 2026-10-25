#include <bits/stdc++.h>
using namespace std;

/*
Problem: LeetCode 55 - Jump Game
Pattern: Greedy

Approach:
-Imagine we're driving from left to right, starting with fuel
 available at the first position.
- Track the remaining fuel while moving left to right.
- At each position, keep our current fuel or replace it
  with nums[i], whichever is greater.
- Spend 1 unit of fuel to move to the next position.
- If fuel becomes negative, we cannot reach this position.

Time: O(n)
Space: O(1)
*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int curr_fuel = nums[0];

        for(int num : nums) {
            if(curr_fuel < 0) {
                return false;
            }

            if(curr_fuel < num) {
                curr_fuel = num;
            }

            curr_fuel--;
        }

        return true;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {2, 3, 1, 1, 4};

    cout << boolalpha << sol.canJump(nums) << endl;

    return 0;
}