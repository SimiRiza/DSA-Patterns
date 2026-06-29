/*
 * Problem:
 * LeetCode 103 - Binary Tree Zigzag Level Order Traversal
 *
 * Approach:
 * 1. Perform a level order traversal using a queue.
 * 2. For each level, place node values either from left-to-right or
 *    right-to-left based on the current traversal direction.
 * 3. Toggle the direction after processing each level.
 *
 * Self-Note: can use built in reverse function to reverse the vector instead of using index manipulation 
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
    void helper(queue<TreeNode*> q, vector<vector<int>> &res, bool is_rev) {
        if (q.empty()) return;

        int n = q.size();
        vector<int> temp(n, 0);

        for (int i = 0; i < n; i++) {
            TreeNode* curr = q.front();

            // Place the current node at the correct index based on traversal direction
            int idx = is_rev ? n - i - 1 : i;
            temp[idx] = curr->val;

            // Store nodes of the next level
            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);

            q.pop();
        }

        res.push_back(temp);

        // Toggle traversal direction for the next level
        helper(q, res, !is_rev);
    }

public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;

        if (!root)
            return res;

        queue<TreeNode*> q;
        q.push(root);

        helper(q, res, false);

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
    vector<vector<int>> ans = obj.zigzagLevelOrder(root);

    cout << "Zigzag Level Order Traversal:" << endl;
    printLevels(ans);

    // Expected Output:
    // [ 3 ]
    // [ 20 9 ]
    // [ 15 7 ]

    return 0;
}