#include <bits/stdc++.h>
using namespace std;

/*
Problem: LeetCode 45 - Jump Game II
Pattern: Recursion + Memoization (Top-Down DP)

Approach:
- From index idx, try every jump from 1 to nums[idx].
- Recursively calculate jumps needed from the next index.
- Choose the minimum valid result.
- Store the answer in dp[idx].

Time: O(n^2)
Space: O(n) DP array + O(n) recursion stack

Self Note:
- dp[idx] stores the minimum jumps needed to reach the last index
  from index idx.
- INT_MAX means the destination is unreachable from that state.
- Only add 1 to result when result != INT_MAX to avoid overflow.
- This is the DP solution; the greedy solution runs in O(n) time.
*/

class Solution {
public:
    int helper(vector<int>& nums, int idx, vector<int>& dp) {
        if(idx >= nums.size() - 1)
            return 0;

        if(dp[idx] != -1)
            return dp[idx];

        int min_jumps = INT_MAX;

        for(int opt = 1; opt <= nums[idx]; opt++) {
            int result = helper(nums, idx + opt, dp);

            if(result != INT_MAX)
                min_jumps = min(min_jumps, 1 + result);
        }

        return dp[idx] = min_jumps;
    }

    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return helper(nums, 0, dp);
    }
};

int main() {
    Solution sol;

    vector<int> nums = {2, 3, 1, 1, 4};

    cout << sol.jump(nums) << endl;

    return 0;
}