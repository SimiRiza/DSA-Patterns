/*
 * Problem:
 * LeetCode 90 - Subsets II
 *
 * Approach:
 * 1. Sort the array so that duplicate elements become adjacent.
 * 2. Use recursion to make two choices at every index:
 *      - Include the current element.
 *      - Exclude the current element.
 * 3. Before the exclusion branch, skip all consecutive duplicates
 *    so that duplicate subsets are not generated.
 * 4. When all elements have been processed, store the current subset.
 *
 * Time Complexity: O(n * 2^n)
 * Space Complexity: O(n) (excluding the output)
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void helper(vector<int>& nums, vector<int> temp,
                vector<vector<int>>& res, int i) {
        if (i >= nums.size()) {
            res.push_back(temp);
            return;
        }

        // Include current element
        temp.push_back(nums[i]);
        helper(nums, temp, res, i + 1);

        // Exclude current element
        temp.pop_back();

        // Skip duplicates
        while (i < nums.size() - 1 && nums[i] == nums[i + 1]) {
            i++;
        }

        helper(nums, temp, res, i + 1);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> res;
        vector<int> temp;

        helper(nums, temp, res, 0);

        return res;
    }
};

int main() {
    Solution obj;

    vector<int> nums = {1, 2, 2};

    vector<vector<int>> ans = obj.subsetsWithDup(nums);

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