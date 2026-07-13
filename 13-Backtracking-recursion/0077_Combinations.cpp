/*
 * Problem:
 * LeetCode 77 - Combinations
 *
 * Approach:
 * 1. Create an array containing numbers from 1 to n.
 * 2. Use backtracking to either:
 *      - Include the current number.
 *      - Exclude the current number.
 * 3. When the current subset size becomes k, store it in the answer.
 * 4. Stop recursion if all numbers have been processed.
 *
 * Time Complexity: O(C(n, k) * k)
 * Space Complexity: O(k) (excluding the output)
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void helper(vector<int>& nums, vector<int>& temp,
                vector<vector<int>>& res, int i, int k) {
        if (temp.size() == k) {
            res.push_back(temp);
            return;
        }

        if (i >= nums.size()) {
            return;
        }

        // Include current number
        temp.push_back(nums[i]);
        helper(nums, temp, res, i + 1, k);

        // Exclude current number
        temp.pop_back();
        helper(nums, temp, res, i + 1, k);
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> nums(n);

        for (int i = 0; i < n; i++) {
            nums[i] = i + 1;
        }

        vector<vector<int>> res;
        vector<int> temp;

        helper(nums, temp, res, 0, k);

        return res;
    }
};

int main() {
    Solution obj;

    int n = 4;
    int k = 2;

    vector<vector<int>> ans = obj.combine(n, k);

    cout << "Combinations:\n";
    for (const auto& combination : ans) {
        cout << "[ ";
        for (int x : combination) {
            cout << x << " ";
        }
        cout << "]\n";
    }

    return 0;
}