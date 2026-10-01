/*
Pattern: Backtracking — Permutations + Duplicate Handling

Approach:
- Sort nums so duplicates are adjacent.
- At each level, choose an unused element.
- If the current element equals the previous one AND
  the previous duplicate has NOT been used at this level,
  skip it.
- This prevents generating duplicate permutations.

Time: O(n * n!)
Space: O(n) recursion stack + used + temp
       Output: O(n * n!)

Self Note:
- Why !used[i-1]?
  If the previous duplicate IS already used in the current path,
  using this duplicate is valid.
  If it is NOT used, choosing this one first would create a
  duplicate branch.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void helper(vector<int>& nums,
                vector<vector<int>>& res,
                vector<int> temp,
                vector<bool> used) {

        if(temp.size() == nums.size()) {
            res.push_back(temp);
            return;
        }

        for(int i = 0; i < nums.size(); i++) {

            // Skip duplicate choice at the same level
            if(i > 0 && nums[i] == nums[i - 1] && !used[i - 1])
                continue;

            if(!used[i]) {

                // Choose
                temp.push_back(nums[i]);
                used[i] = true;

                helper(nums, res, temp, used);

                // Backtrack
                temp.pop_back();
                used[i] = false;
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {

        vector<vector<int>> res;
        vector<int> temp = {};
        vector<bool> used(nums.size(), false);

        sort(nums.begin(), nums.end());

        helper(nums, res, temp, used);

        return res;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {1, 1, 2};

    vector<vector<int>> ans = sol.permuteUnique(nums);

    for(auto permutation : ans) {
        cout << "[ ";
        for(int x : permutation)
            cout << x << " ";
        cout << "]\n";
    }

    return 0;
}