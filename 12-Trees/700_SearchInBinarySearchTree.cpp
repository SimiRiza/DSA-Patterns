/*
 * Problem:
 * LeetCode 700 - Search in a Binary Search Tree
 *
 * Approach:
 * 1. Start from the root.
 * 2. If the target is smaller, move to the left subtree.
 * 3. If the target is larger, move to the right subtree.
 * 4. If the target is found, return the corresponding node.
 * 5. If the traversal reaches a null node, the value does not exist.
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
    TreeNode* searchBST(TreeNode* root, int val) {
        while (root) {
            // Search continues in the left subtree
            if (val < root->val)
                root = root->left;

            // Search continues in the right subtree
            else if (val > root->val)
                root = root->right;

            // Target value found
            else
                return root;
        }

        return nullptr;
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
    //         4
    //       /   \
    //      2     7
    //     / \
    //    1   3

    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    Solution obj;

    TreeNode* ans = obj.searchBST(root, 2);

    if (ans) {
        cout << "Subtree rooted at " << ans->val << ":" << endl;
        inorder(ans);
    } else {
        cout << "Value not found.";
    }

    // Expected Output:
    // Subtree rooted at 2:
    // 1 2 3

    return 0;
}