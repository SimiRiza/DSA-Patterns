/*
 * Problem:
 * LeetCode 103 - Binary Tree Zigzag Level Order Traversal
 *
 * Approach:
 * 1. Perform a level order traversal using a queue.
 * 2. For each level, place node values directly at their zigzag position.
 * 3. Toggle the traversal direction after every level.
 *
 * self-Note: can use built in reverse function to reverse the vector instead of using index manipulation
 *            and is_rev = !is_rev instead of if,else statements
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;

        if (!root)
            return res;

        queue<TreeNode*> q;
        q.push(root);

        bool is_rev = false;

        while (!q.empty()) {
            int n = q.size();
            vector<int> temp(n, 0);

            for (int i = 0; i < n; i++) {
                TreeNode* curr = q.front();

                // Place the value at the correct position for zigzag order
                int idx = is_rev ? n - i - 1 : i;
                temp[idx] = curr->val;

                // Store nodes of the next level
                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);

                q.pop();
            }

            // Alternate traversal direction for the next level
            if (is_rev) {
            is_rev = false;
            } else is_rev = true;

            res.push_back(temp);
        }

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