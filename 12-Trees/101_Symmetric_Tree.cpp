/*
 * Problem:
 * LeetCode 101 - Symmetric Tree
 *
 * Approach:
 * 1. Compare the left and right subtrees recursively.
 * 2. If both nodes are null, they are symmetric.
 * 3. If only one node is null or values differ, return false.
 * 4. Recursively compare:
 *    - Left subtree of left node with right subtree of right node.
 *    - Right subtree of left node with left subtree of right node.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(h)
 * (h = height of the tree due to recursion stack)
 */

#include <iostream>
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
    bool is_inverted(TreeNode* l, TreeNode* r) {
        if (!l && !r)
            return true;

        // One node exists while the other doesn't
        if ((!l && r) || (!r && l))
            return false;

        // Current nodes must have the same value
        if (l->val == r->val) {
            // Compare mirror children
            return is_inverted(l->left, r->right) &&
                   is_inverted(r->left, l->right);
        }

        return false;
    }

public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;   // Empty tree is symmetric
        return is_inverted(root->left, root->right);
    }
};

int main() {
    // Test Case:
    //         1
    //       /   \
    //      2     2
    //     / \   / \
    //    3   4 4   3

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(2);

    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);

    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    Solution obj;

    if (obj.isSymmetric(root))
        cout << "Tree is symmetric." << endl;
    else
        cout << "Tree is not symmetric." << endl;

    // Expected Output:
    // Tree is symmetric.

    return 0;
}