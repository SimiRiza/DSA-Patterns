#include <bits/stdc++.h>
using namespace std;

/*
Problem: 78. Subsets
Pattern: Recursion — Include / Exclude

Approach:
- At every index, we have 2 choices:
    1. Include nums[i]
    2. Exclude nums[i]
- Recursively explore both choices.
- When we reach the end, store the current subset.

Time: O(n * 2^n)
Space: O(n) recursion stack
       O(n) temporary subset
       Output: O(n * 2^n)
*/

class Solution {
public:
    void add_remove(vector<int>& nums, vector<int>& temp, int i,
                    vector<vector<int>>& ans) {

        if(i == nums.size()) {
            ans.push_back(temp);
            return;
        }

        // Include
        temp.push_back(nums[i]);
        add_remove(nums, temp, i + 1, ans);

        // Backtrack
        temp.pop_back();

        // Exclude
        add_remove(nums, temp, i + 1, ans);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp = {};

        add_remove(nums, temp, 0, ans);

        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {1, 2, 3};

    vector<vector<int>> ans = sol.subsets(nums);

    for(auto subset : ans) {
        cout << "[ ";
        for(int x : subset)
            cout << x << " ";
        cout << "]\n";
    }

    return 0;
}