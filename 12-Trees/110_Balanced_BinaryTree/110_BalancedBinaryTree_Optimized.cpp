/*
 * Problem:
 * LeetCode 110 - Balanced Binary Tree
 *
 * Approach:
 * 1. Perform a postorder DFS.
 * 2. Compute the height of the left and right subtrees.
 * 3. If either subtree is already unbalanced, propagate -1 upward.
 * 4. If the current node is unbalanced, return -1.
 * 5. Otherwise, return the height of the current subtree.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(h)
 * (h = height of the tree due to recursion stack)
 */

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

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
public:
    int getHeight_if_balanced(TreeNode* root) {
        if (!root)
            return 0;

        int leftheight = getHeight_if_balanced(root->left);

        // Left subtree is already unbalanced
        if (leftheight == -1)
            return -1;

        int rytheight = getHeight_if_balanced(root->right);

        // Right subtree is already unbalanced
        if (rytheight == -1)
            return -1;

        // Current node is balanced
        if (abs(leftheight - rytheight) <= 1)
            return 1 + max(leftheight, rytheight);

        // Current node is unbalanced
        return -1;
    }

    bool isBalanced(TreeNode* root) {
        int h = getHeight_if_balanced(root);

        if (h == -1)
            return false;

        return true;
    }
};

int main() {
    // Test Case:
    //
    //         3
    //       /   \
    //      9     20
    //           /  \
    //          15   7
    //
    // Expected: Balanced

    TreeNode* root = new TreeNode(3);

    root->left = new TreeNode(9);
    root->right = new TreeNode(20);

    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution obj;

    if (obj.isBalanced(root))
        cout << "Tree is balanced." << endl;
    else
        cout << "Tree is not balanced." << endl;

    // Expected Output:
    // Tree is balanced.

    return 0;
}