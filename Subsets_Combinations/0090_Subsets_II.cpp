#include <bits/stdc++.h>
using namespace std;

/*
Problem: 90. Subsets II
Pattern: Recursion — Include / Exclude + Duplicate Handling

Approach:
- Sort the array so duplicates are adjacent.
- TAKE → include current element normally.
- NOT TAKE → skip all duplicates of current element.
- This prevents generating duplicate subsets.

Time: O(n * 2^n)
Space: O(n) recursion stack + current subset
       Output: O(n * 2^n)

Self Note:
- Every subset comes from TAKE or NOT TAKE.
- Duplicate subsets happen when duplicate elements are
  separately skipped/taken.
- TAKE is explored normally.
- In NOT TAKE, skip all duplicates.
- Sorting is necessary to make duplicates adjacent.

Key:
TAKE → i + 1
NOT TAKE → skip duplicates → i + 1
*/

class Solution {
public:
    void add_remove(vector<int>& nums, vector<vector<int>>& ans,
                    vector<int>& temp, int i) {

        if (i == nums.size()) {
            ans.push_back(temp);
            return;
        }

        // TAKE
        temp.push_back(nums[i]);
        add_remove(nums, ans, temp, i + 1);

        // Backtrack
        temp.pop_back();

        // NOT TAKE → skip duplicates
        while (i + 1 < nums.size() &&
               nums[i] == nums[i + 1])
            i++;

        add_remove(nums, ans, temp, i + 1);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<int> temp = {};

        add_remove(nums, ans, temp, 0);

        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {1, 2, 2};

    vector<vector<int>> ans = sol.subsetsWithDup(nums);

    for (auto subset : ans) {
        cout << "[ ";
        for (int x : subset)
            cout << x << " ";
        cout << "]\n";
    }

    return 0;
}