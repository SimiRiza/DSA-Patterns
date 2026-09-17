/*
 * Problem:
 * LeetCode 94 - Binary Tree Inorder Traversal
 *
 * Approach:
 * 1. Use recursion to perform an inorder traversal.
 * 2. Visit the left subtree.
 * 3. Store the current node's value.
 * 4. Visit the right subtree.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(h)
 * (h = height of the tree, due to recursion stack)
 */

#include <iostream>
#include <vector>
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
    void Helper_inorderTraversal(TreeNode* root, vector<int> &res) {
        if (!root) return;

        Helper_inorderTraversal(root->left, res);   // Visit left subtree
        res.push_back(root->val);                   // Process current node
        Helper_inorderTraversal(root->right, res);  // Visit right subtree
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        Helper_inorderTraversal(root, res);
        return res;
    }
};

void printVector(const vector<int>& res) {
    for (int val : res)
        cout << val << " ";
    cout << endl;
}

int main() {
    // Test Case:
    //      1
    //       \
    //        2
    //       /
    //      3

    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution obj;
    vector<int> ans = obj.inorderTraversal(root);

    cout << "Inorder Traversal: ";
    printVector(ans);

    // Expected Output:
    // Inorder Traversal: 1 3 2

    return 0;
}