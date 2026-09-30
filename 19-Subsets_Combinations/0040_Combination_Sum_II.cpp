#include <bits/stdc++.h>
using namespace std;

/*
Problem: 40. Combination Sum II
Pattern: Recursion — Include / Exclude + Duplicate Handling

Approach:
- Each element can be used only once → include uses i + 1.
- Sort first so duplicate elements become adjacent.
- Include the current element normally.
- For the exclude branch, skip ALL duplicates of the current element.
- This prevents generating the same combination multiple times.

Time: O(2^n * n)
Space: O(n) recursion stack + current subset
        Output space not included

Self Note:
- Normal subset recursion gives TAKE / NOT TAKE.
- The problem is duplicate elements can create duplicate answers.
- Example: [1,1,2]
- If we skip the first 1, then choosing the second 1
  in the NOT TAKE branch can create the same subset again.
- Therefore:
      TAKE → consider the element normally
      NOT TAKE → skip all its duplicates
- Sorting is necessary so duplicates are next to each other.
*/

class Solution {
public:
    void add_remove(vector<int>& candidates, int target, int i, int sum,
                    vector<int> temp, vector<vector<int>>& ans) {

        if(sum == target) {
            ans.push_back(temp);
            return;
        }

        if(i >= candidates.size() || sum > target) {
            return;
        }

        // TAKE
        sum += candidates[i];
        temp.push_back(candidates[i]);

        add_remove(candidates, target, i + 1, sum, temp, ans);

        // Backtrack
        sum -= candidates[i];
        temp.pop_back();

        // NOT TAKE → skip all duplicates
        while(i + 1 < candidates.size() &&
              candidates[i + 1] == candidates[i]) {
            i++;
        }

        add_remove(candidates, target, i + 1, sum, temp, ans);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates,
                                        int target) {

        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> temp = {};

        add_remove(candidates, target, 0, 0, temp, ans);

        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;

    vector<vector<int>> ans =
        sol.combinationSum2(candidates, target);

    for(auto combination : ans) {
        cout << "[ ";
        for(int x : combination)
            cout << x << " ";
        cout << "]\n";
    }

    return 0;
}