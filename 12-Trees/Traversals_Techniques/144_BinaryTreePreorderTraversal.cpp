/*
 * Problem:
 * LeetCode 144 - Binary Tree Preorder Traversal
 *
 * Approach:
 * 1. Use recursion to perform a preorder traversal.
 * 2. Visit the current node.
 * 3. Traverse the left subtree.
 * 4. Traverse the right subtree.
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
    void helper_preorderTraversal(TreeNode* root, vector<int> &res) {
        if (!root) return;

        res.push_back(root->val);                    // Process current node
        helper_preorderTraversal(root->left, res);   // Traverse left subtree
        helper_preorderTraversal(root->right, res);  // Traverse right subtree
    }

public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        helper_preorderTraversal(root, res);
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
    vector<int> ans = obj.preorderTraversal(root);

    cout << "Preorder Traversal: ";
    printVector(ans);

    // Expected Output:
    // Preorder Traversal: 1 2 3

    return 0;
}