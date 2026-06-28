/*
 * Problem:
 * LeetCode 145 - Binary Tree Postorder Traversal
 *
 * Approach:
 * 1. Use recursion to perform a postorder traversal.
 * 2. Traverse the left subtree.
 * 3. Traverse the right subtree.
 * 4. Visit the current node.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(h)
 * (h = height of the tree due to recursion stack)
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
    void helper_postorderTraversal(TreeNode* root, vector<int> &res) {
        if (!root) return;

        helper_postorderTraversal(root->left, res);   // Traverse left subtree
        helper_postorderTraversal(root->right, res);  // Traverse right subtree
        res.push_back(root->val);                     // Process current node
    }

public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        helper_postorderTraversal(root, res);
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
    vector<int> ans = obj.postorderTraversal(root);

    cout << "Postorder Traversal: ";
    printVector(ans);

    // Expected Output:
    // Postorder Traversal: 3 2 1

    return 0;
}