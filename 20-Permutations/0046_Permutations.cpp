#include <bits/stdc++.h>
using namespace std;

/*
Pattern: Backtracking — Choose / Unchoose

Approach:
- At every position, try every unused element.
- Mark it as used before recursion.
- After recursion, undo the choice.
- When temp contains all elements, store the permutation.

Time: O(n * n!)
Space: O(n) recursion stack + used + current permutation
       Output: O(n * n!)

Self Note:
- Unlike subsets, we don't have TAKE / NOT TAKE.
- Every level must choose exactly ONE unused element.
- Backtracking = choose → recurse → undo.
*/

class Solution {
public:
    void take_callback(vector<int>& nums,
                       vector<vector<int>>& ans,
                       vector<bool>& used,
                       vector<int>& temp) {

        if(temp.size() == nums.size()) {
            ans.push_back(temp);
            return;
        }

        for(int i = 0; i < used.size(); i++) {

            if(!used[i]) {

                // Choose
                temp.push_back(nums[i]);
                used[i] = true;

                take_callback(nums, ans, used, temp);

                // Backtrack
                temp.pop_back();
                used[i] = false;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>> ans;
        vector<bool> used(nums.size(), false);
        vector<int> temp = {};

        take_callback(nums, ans, used, temp);

        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {1, 2, 3};

    vector<vector<int>> ans = sol.permute(nums);

    for(auto permutation : ans) {
        cout << "[ ";
        for(int x : permutation)
            cout << x << " ";
        cout << "]\n";
    }

    return 0;
}