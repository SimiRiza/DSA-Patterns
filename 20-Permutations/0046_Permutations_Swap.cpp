#include <bits/stdc++.h>
using namespace std;

/*
Pattern: Backtracking - Swap

Approach:
- At index i, try every element from i to n-1.
- Swap it into position i.
- Recurse for the next position.
- Swap back to restore the array.

Time: O(n * n!)
Space: O(n) recursion stack
Output: O(n * n!)

Self Note:
Instead of using a used[] array, we use swapping.
Choose → Recurse → Undo
The swap-back is the backtracking step.
*/

class Solution {
public:
    void Swap_check(vector<int>& nums,
                    vector<vector<int>>& ans,
                    vector<int>& temp,
                    int i) {

        if(i == nums.size()) {
            ans.push_back(temp);
            return;
        }

        for(int j = i; j < nums.size(); j++) {

            // Choose
            swap(temp[i], temp[j]);

            // Recurse
            Swap_check(nums, ans, temp, i + 1);

            // Backtrack
            swap(temp[i], temp[j]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp = nums;

        Swap_check(nums, ans, temp, 0);

        return ans;
    }
};

int main() {

    Solution sol;

    vector<int> nums = {1, 2, 3};

    vector<vector<int>> ans = sol.permute(nums);

    for(auto permutation : ans) {
        cout << "[ ";
        for(int x : permutation) {
            cout << x << " ";
        }
        cout << "]\n";
    }

    return 0;
}