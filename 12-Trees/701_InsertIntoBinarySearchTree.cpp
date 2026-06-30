/*
 * Problem:
 * LeetCode 701 - Insert into a Binary Search Tree
 *
 * Approach:
 * 1. Create a new node with the given value.
 * 2. Traverse the BST iteratively.
 * 3. Move left if the value is smaller, otherwise move right.
 * 4. Insert the new node when an empty position is found.
 *
 * Time Complexity: O(h)
 * Space Complexity: O(1)
 * (h = height of the tree)
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
    TreeNode* insertIntoBST(TreeNode* Root, int val) {
        TreeNode* root = Root;
        TreeNode* NN = new TreeNode(val);

        if (!Root)
            return NN;

        while (root) {
            if (val < root->val) {
                // Insert as the left child when the position is available
                if (!root->left) {
                    root->left = NN;
                    break;
                }

                root = root->left;
            }

            else if (val > root->val) {
                // Insert as the right child when the position is available
                if (!root->right) {
                    root->right = NN;
                    break;
                }

                root = root->right;
            }
        }

        return Root;
    }
};

void inorder(TreeNode* root) {
    if (!root) return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    // Test Case:
    // Initial BST:
    //       4
    //      / \
    //     2   7
    //    / \
    //   1   3
    //
    // Insert: 5

    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    Solution obj;
    root = obj.insertIntoBST(root, 5);

    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;

    // Expected Output:
    // Inorder Traversal: 1 2 3 4 5 7

    return 0;
}