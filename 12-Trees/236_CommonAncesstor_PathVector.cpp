/**
 * Approach: Store Root-to-Node Paths
 *
 * Intuition:
 * - Find the path from the root to node p.
 * - Find the path from the root to node q.
 * - Compare both paths from the root until they differ.
 * - The last common node is the Lowest Common Ancestor (LCA).
 *
 * Algorithm:
 * 1. Recursively find the path from root to p.
 * 2. Recursively find the path from root to q.
 * 3. Store both paths in vectors.
 * 4. Compare the vectors from the end (root side).
 * 5. Return the last common node.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */

#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
    bool findPath(TreeNode* root, TreeNode* p, vector<TreeNode*>& p_path) {
        if (root == nullptr)
            return false;

        if (root == p) {
            p_path.push_back(root);
            return true;
        }

        if (findPath(root->left, p, p_path) ||
            findPath(root->right, p, p_path)) {
            p_path.push_back(root);
            return true;
        }

        return false;
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        vector<TreeNode*> p_path;
        vector<TreeNode*> q_path;

        findPath(root, p, p_path);
        findPath(root, q, q_path);

        int i = p_path.size() - 1;
        int j = q_path.size() - 1;

        TreeNode* ans = nullptr;

        while (i >= 0 && j >= 0 && p_path[i] == q_path[j]) {
            ans = p_path[i];
            i--;
            j--;
        }

        return ans;
    }
};

int main() {
    /*
             3
            / \
           5   1
          / \ / \
         6  2 0  8
           / \
          7   4
    */

    TreeNode* root = new TreeNode(3);

    root->left = new TreeNode(5);
    root->right = new TreeNode(1);

    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);

    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);

    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    TreeNode* p = root->left;                // Node 5
    TreeNode* q = root->left->right->right;  // Node 4

    Solution obj;

    TreeNode* ans = obj.lowestCommonAncestor(root, p, q);

    if (ans)
        cout << "Lowest Common Ancestor: " << ans->val << endl;
    else
        cout << "LCA not found." << endl;

    return 0;
}