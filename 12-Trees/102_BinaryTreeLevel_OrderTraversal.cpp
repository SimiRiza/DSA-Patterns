/*
 * Problem:
 * LeetCode 102 - Binary Tree Level Order Traversal
 *
 * Approach:
 * 1. Use a queue to perform Breadth-First Search (BFS).
 * 2. Process all nodes at the current level.
 * 3. Store their values and enqueue their children.
 * 4. Repeat until all levels are traversed.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */

#include <iostream>
#include <vector>
#include <queue>
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
    void helper(queue<TreeNode*> &q, vector<vector<int>> &res) {
        if (q.empty()) return;

        vector<int> temp;
        int n = q.size();   // Number of nodes in the current level

        for (int i = 0; i < n; i++) {
            TreeNode* curr_node = q.front();
            temp.push_back(curr_node->val);

            // Enqueue children for the next level
            if (curr_node->left)
                q.push(curr_node->left);
            if (curr_node->right)
                q.push(curr_node->right);

            q.pop();
        }

        res.push_back(temp);

        // Process the next level
        if (!q.empty())
            helper(q, res);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;

        if (root == nullptr)
            return res;

        q.push(root);
        helper(q, res);

        return res;
    }
};

void printLevels(const vector<vector<int>>& levels) {
    for (const auto& level : levels) {
        cout << "[ ";
        for (int val : level)
            cout << val << " ";
        cout << "]" << endl;
    }
}

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
    vector<vector<int>> ans = obj.levelOrder(root);

    cout << "Level Order Traversal:" << endl;
    printLevels(ans);

    // Expected Output:
    // [ 3 ]
    // [ 9 20 ]
    // [ 15 7 ]

    return 0;
}