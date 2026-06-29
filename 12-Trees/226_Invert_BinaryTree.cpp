/*
 * Problem:
 * LeetCode 226 - Invert Binary Tree
 *
 * Approach:
 * 1. Recursively traverse the tree.
 * 2. Invert the left subtree.
 * 3. Swap the left and right child pointers.
 * 4. Invert the original right subtree (now the left subtree after swapping).
 *
 * After swapping, recurse into the subtree that has not been processed yet.
 * The original right subtree becomes the left child after the swap.
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
public:
    void helper(TreeNode* root) {
        if (!root) return;

        helper(root->left);

        // Swap the left and right child pointers
        TreeNode* l = root->left;
        TreeNode* r = root->right;
        root->left = r;
        root->right = l;

        // Continue on the original right subtree (now on the left)
        helper(root->left);
    }

    TreeNode* invertTree(TreeNode* root) {
        helper(root);
        return root;
    }
};

void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    // Original Tree:
    //       4
    //     /   \
    //    2     7
    //   / \   / \
    //  1  3  6  9

    TreeNode* root = new TreeNode(4);

    root->left = new TreeNode(2);
    root->right = new TreeNode(7);

    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);

    Solution obj;
    root = obj.invertTree(root);

    cout << "Inorder Traversal After Inversion: ";
    inorder(root);
    cout << endl;

    // Expected Output:
    // Inorder Traversal After Inversion: 9 7 6 4 3 2 1

    return 0;
}