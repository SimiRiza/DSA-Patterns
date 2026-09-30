#include <bits/stdc++.h>
using namespace std;

/*
Pattern: Recursion — Include / Exclude

Approach:
- At each candidate, we have 2 choices:
    1. Include it → stay at the same index because it can be reused.
    2. Exclude it → move to the next index.
- Stop when:
    sum == target → store combination
    sum > target  → invalid path
    i >= n        → no candidates left

Time: Exponential — depends on target and candidate values
Space: O(target) recursion depth in the worst case
       Output space not included

Self Note:
- The key idea is staying at the same index after choosing a number.
- This allows unlimited reuse of the same candidate.
- Unlike Subsets/Combinations, the include branch does NOT do i + 1.
*/

class Solution {
public:
    void add_checksum(vector<int>& candidates, int target,
                      vector<vector<int>>& ans, int i, int sum,
                      vector<int> temp) {

        if(i >= candidates.size())
            return;

        if(sum == target) {
            ans.push_back(temp);
            return;
        }

        if(sum > target)
            return;

        // Include current candidate
        sum += candidates[i];
        temp.push_back(candidates[i]);

        add_checksum(candidates, target, ans, i, sum, temp);

        // Backtrack
        sum -= candidates[i];
        temp.pop_back();

        // Exclude current candidate
        add_checksum(candidates, target, ans, i + 1, sum, temp);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp = {};

        add_checksum(candidates, target, ans, 0, 0, temp);

        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;

    vector<vector<int>> ans = sol.combinationSum(candidates, target);

    for(auto combination : ans) {
        cout << "[ ";
        for(int x : combination)
            cout << x << " ";
        cout << "]\n";
    }

    return 0;
}