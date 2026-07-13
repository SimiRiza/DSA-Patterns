/*
 * Problem:
 * LeetCode 78 - Subsets
 *
 * Approach:
 * 1. Use recursive backtracking to generate all possible subsets.
 * 2. At each index, make two choices:
 *      - Include the current element.
 *      - Exclude the current element.
 * 3. When all elements have been processed, store the current subset.
 *
 * Time Complexity: O(n * 2^n)
 * Space Complexity: O(n) (excluding the output)
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void subsetsHelper(vector<int>& nums, int i,
                       vector<int> temp,
                       vector<vector<int>>& res) {
        if (i == nums.size()) {
            res.push_back(temp);
            return;
        }

        // Include current element
        temp.push_back(nums[i]);
        subsetsHelper(nums, i + 1, temp, res);

        // Exclude current element
        temp.pop_back();
        subsetsHelper(nums, i + 1, temp, res);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        subsetsHelper(nums, 0, {}, res);
        return res;
    }
};

int main() {
    Solution obj;

    vector<int> nums = {1, 2, 3};

    vector<vector<int>> ans = obj.subsets(nums);

    cout << "Subsets:\n";
    for (const auto& subset : ans) {
        cout << "[ ";
        for (int x : subset) {
            cout << x << " ";
        }
        cout << "]\n";
    }

    return 0;
}