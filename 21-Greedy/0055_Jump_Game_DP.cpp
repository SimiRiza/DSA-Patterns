#include <bits/stdc++.h>
using namespace std;

/*
Problem: LeetCode 55 - Jump Game
Pattern: Recursion + Memoization (Top-Down DP)

Approach:
- From index idx, try every possible jump from 1 to nums[idx].
- Recursively check whether any reachable position can reach the end.
- Store the result for each index in dp[].
    - -1 → not calculated
    -  0 → cannot reach the end
    -  1 → can reach the end

Time: O(n^2)
Space: O(n) dp + O(n) recursion stack

Self Note:
- The important idea is:
      "Can I reach the end from this index?"
- This is a top-down DP / memoization version.
*/

class Solution {
public:

    bool helper(vector<int>& nums, int idx, vector<int>& dp) {

        if(idx >= nums.size() - 1) {
            dp[idx] = 1;
            return true;
        }

        if(dp[idx] == 0)
            return false;

        if(dp[idx] == 1)
            return true;

        if(dp[idx] == -1) {

            for(int i = 1; i <= nums[idx]; i++) {

                if(helper(nums, idx + i, dp)) {
                    dp[idx] = 1;
                    return true;
                }
            }
        }

        dp[idx] = 0;
        return false;
    }

    bool canJump(vector<int>& nums) {

        vector<int> dp(nums.size(), -1);

        return helper(nums, 0, dp);
    }
};

int main() {

    Solution sol;

    vector<int> nums = {2, 3, 1, 1, 4};

    cout << boolalpha << sol.canJump(nums) << endl;

    return 0;
}