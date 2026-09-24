#include <bits/stdc++.h>
using namespace std;

/*
Problem: 77. Combinations
Pattern: Recursion — Include / Exclude

Approach:
- Start from number 1.
- At every number, choose:
    1. Include it
    2. Exclude it
- When temp contains k elements, store the combination.
- Stop if num goes beyond n.

Time: O(C(n,k) * k)
Space: O(k) recursion stack + current combination
       Output: O(C(n,k) * k)

Self Note:
- This is the same include/exclude pattern as Subsets.
- Difference: here we only store subsets having exactly k elements.
*/

class Solution {
public:
    void add_remove(int num, int n, int k, vector<int>& temp,
                    vector<vector<int>>& ans) {

        if(temp.size() == k) {
            ans.push_back(temp);
            return;
        }

        if(num > n)
            return;

        // Include
        temp.push_back(num);
        add_remove(num + 1, n, k, temp, ans);

        // Backtrack
        temp.pop_back();

        // Exclude
        add_remove(num + 1, n, k, temp, ans);
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp = {};

        add_remove(1, n, k, temp, ans);

        return ans;
    }
};

int main() {
    Solution sol;

    int n = 4;
    int k = 2;

    vector<vector<int>> ans = sol.combine(n, k);

    for(auto combination : ans) {
        cout << "[ ";
        for(int x : combination)
            cout << x << " ";
        cout << "]\n";
    }

    return 0;
}