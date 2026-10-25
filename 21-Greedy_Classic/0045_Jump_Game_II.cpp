#include <bits/stdc++.h>
using namespace std;

/*
Problem: LeetCode 45 - Jump Game II
Pattern: Greedy — Level Boundary

Approach:
- farthest stores the maximum index reachable so far.
- curr_jumps_left marks the boundary of the current jump range.
- When i reaches this boundary, we must take another jump.
- Update the boundary to farthest.

Time: O(n)
Space: O(1)

Self Note:
Think of each jump as expanding a reachable range.
*/

class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() == 1)
            return 0;

        int jumps = 0;
        int left = nums.size() - 1;
        int curr_jumps_left = 0;
        int farthest = 0;

        for(int i = 0; i < nums.size() - 1; i++) {
            farthest = max(farthest, i + nums[i]);

            if(i == curr_jumps_left) {
                jumps++;
                curr_jumps_left = farthest;
            }
        }

        return jumps;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {2, 3, 1, 1, 4};

    cout << sol.jump(nums) << endl;

    return 0;
}