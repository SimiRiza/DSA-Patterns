#include <bits/stdc++.h>
using namespace std;

/*
Problem: LeetCode 55 - Jump Game
Pattern: Greedy — Maximum Reachable Index

Approach:
- Track the farthest index reachable so far.
- If the current index is beyond maxIdx_reachable, return false.
- Otherwise, update the farthest reachable index using i + nums[i].
- If we finish the loop, the last index is reachable.

Time: O(n)
Space: O(1)

*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxIdx_reachable = 0;

        for(int i = 0; i < nums.size(); i++) {
            int curr_maxreachabale = i + nums[i];

            if(maxIdx_reachable < i)
                return false;

            maxIdx_reachable = max(maxIdx_reachable,
                                   curr_maxreachabale);
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