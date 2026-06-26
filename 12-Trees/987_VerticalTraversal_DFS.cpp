/**
 * Approach: DFS + Coordinate Mapping
 *
 * Intuition:
 * - Assign each node a coordinate (x, y).
 * - Store each node as (row, value) for every column.
 * - Sort nodes in each column first by row, then by value.
 * - Collect the values column by column.
 *
 * Algorithm:
 * 1. Perform DFS while tracking (x, y) coordinates.
 * 2. Store (row, value) for each column.
 * 3. Sort each column.
 * 4. Extract values to form the answer.
 *
 * Time Complexity: O(n log n)
 * Space Complexity: O(n)
 */

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
    void vertical(TreeNode* root, int x, int y,
                  map<int, vector<pair<int, int>>>& mp) {

        if (root == nullptr)
            return;

        mp[x].push_back({y, root->val});

        vertical(root->left, x - 1, y + 1, mp);
        vertical(root->right, x + 1, y + 1, mp);
    }

public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {

        map<int, vector<pair<int, int>>> mp;
        vector<vector<int>> res;

        vertical(root, 0, 0, mp);

        for (auto& [x, column] : mp) {

            sort(column.begin(), column.end());

            vector<int> temp;

            for (auto& [y, val] : column)
                temp.push_back(val);

            res.push_back(temp);
        }

        return res;
    }
};

int main() {
    /*
            3
           / \
          9  20
            /  \
           15   7

    Expected:
    9
    3 15
    20
    7
    */

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution obj;

    vector<vector<int>> ans = obj.verticalTraversal(root);

    cout << "Vertical Traversal:\n";

    for (auto& col : ans) {
        for (int x : col)
            cout << x << " ";
        cout << endl;
    }

    return 0;
}