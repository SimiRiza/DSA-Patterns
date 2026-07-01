/*
 * Problem:
 * LeetCode 543 - Diameter of Binary Tree
 *
 * Approach:
 * 1. Perform a postorder DFS to compute the height of each subtree.
 * 2. At every node, the diameter passing through it is:
 *        left subtree height + right subtree height.
 * 3. Keep updating the maximum diameter encountered.
 * 4. Return the height of the current subtree to the parent.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(h)
 * (h = height of the tree due to recursion stack)
 */

#include <iostream>
#include <algorithm>
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
    int max_dia = 0;

    int findmax_diameter(TreeNode* root) {
        if (!root)
            return 0;

        int left_ht = findmax_diameter(root->left);
        int ryt_ht = findmax_diameter(root->right);

        // Diameter passing through the current node
        max_dia = max(max_dia, left_ht + ryt_ht);

        // Return the height of the current subtree
        return 1 + max(left_ht, ryt_ht);
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        findmax_diameter(root);
        return max_dia;
    }
};

int main() {
    // Test Case:
    //
    //         1
    //        / \
    //       2   3
    //      / \
    //     4   5
    //
    // Diameter = 3 (4 -> 2 -> 1 -> 3)

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution obj;

    cout << "Diameter: " << obj.diameterOfBinaryTree(root) << endl;

    // Expected Output:
    // Diameter: 3

    return 0;
}