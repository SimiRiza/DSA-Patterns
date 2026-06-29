/*
 * Problem:
 * LeetCode 104 - Maximum Depth of Binary Tree
 *
 * Approach:
 * 1. If the current node is null, its depth is 0.
 * 2. Recursively find the depth of the left and right subtrees.
 * 3. Return 1 plus the maximum of the two depths.
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
public:
    int maxDepth(TreeNode* root) {
        if (!root)
            return 0;

        // Current depth = 1 + deeper subtree
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
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

    cout << "Maximum Depth: " << obj.maxDepth(root) << endl;

    // Expected Output:
    // Maximum Depth: 3

    return 0;
}