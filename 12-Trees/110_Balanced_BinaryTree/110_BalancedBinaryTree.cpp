/*
 * Problem:
 * LeetCode 110 - Balanced Binary Tree
 *
 * Approach:
 * 1. Compute the height of the left and right subtrees.
 * 2. Check if their height difference is at most 1.
 * 3. Recursively verify that both subtrees are also balanced.
 *
 * Time Complexity: O(n²)
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
    int getHeight(TreeNode* root) {
        if (!root)
            return 0;

        // Height = 1 + maximum height of both subtrees
        return 1 + max(getHeight(root->left), getHeight(root->right));
    }

    bool isBalanced(TreeNode* root) {
        if (!root)
            return true;

        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);

        // Current node is balanced only if:
        // 1. Height difference is at most 1.
        // 2. Left subtree is balanced.
        // 3. Right subtree is balanced.
        if ((abs(leftHeight - rightHeight) <= 1) &&
            isBalanced(root->left) &&
            isBalanced(root->right)) {
            return true;
        } else
            return false;
    }
};

int main() {
    // Test Case:
    //         3
    //       /   \
    //      9     20
    //           /  \
    //          15   7

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