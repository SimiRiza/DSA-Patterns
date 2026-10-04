#include <bits/stdc++.h>
using namespace std;

/*
Pattern: Backtracking - Permutations with Constraint

Approach:
This is basically permutation backtracking,
but we DON'T explore every permutation blindly.

At each position:
    1. Check whether the number is valid.
    2. Choose it.
    3. Recurse.
    4. Undo the choice.

Time: O(n!)
Space: O(n) recursion stack + used + temp

Self Note:
position = temp.size() + 1

Valid condition:
nums[i] % position == 0 ||
position % nums[i] == 0

*/

class Solution {
public:

    int count;

    void find_perm(vector<int>& nums,
                   vector<int>& temp,
                   vector<bool>& used) {

        if(temp.size() == nums.size()) {
            count++;
            return;
        }

        int position = temp.size() + 1;

        for(int i = 0; i < nums.size(); i++) {

            if(!used[i] &&
               (nums[i] % position == 0 ||
                position % nums[i] == 0)) {

                // Choose
                temp.push_back(nums[i]);
                used[i] = true;

                // Explore
                find_perm(nums, temp, used);

                // Backtrack
                temp.pop_back();
                used[i] = false;
            }
        }
    }

    int countArrangement(int n) {

        count = 0;

        vector<int> nums(n);
        for(int i = 1; i <= n; i++)
            nums[i - 1] = i;

        vector<int> temp;
        vector<bool> used(n, false);

        find_perm(nums, temp, used);

        return count;
    }
};

int main() {

    Solution sol;

    int n = 3;

    cout << sol.countArrangement(n) << endl;

    return 0;
}