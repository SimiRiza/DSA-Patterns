/*
 * Problem:
 * LeetCode 199 - Binary Tree Right Side View
 *
 * Approach:
 * 1. Perform a level order traversal using a queue.
 * 2. For each level, identify the last node processed.
 * 3. Store the value of the last node, as it is visible from the right side.
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
    vector<int> rightSideView(TreeNode* root) {
        if (!root)
            return {};

        queue<TreeNode*> q;
        q.push(root);

        vector<int> ans;

        while (!q.empty()) {
            int n = q.size();

            for (int i = 0; i < n; i++) {

                // The last node of the current level is visible from the right
                if (i == n - 1)
                    ans.push_back(q.front()->val);

                // Store nodes of the next level
                if (q.front()->left)
                    q.push(q.front()->left);

                if (q.front()->right)
                    q.push(q.front()->right);

                q.pop();
            }
        }

        return ans;
    }
};

void printVector(const vector<int>& ans) {
    for (int val : ans)
        cout << val << " ";
    cout << endl;
}

int main() {
    // Test Case:
    //
    //         1
    //       /   \
    //      2     3
    //       \     \
    //        5     4
    //
    // Right Side View: 1 3 4

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);

    Solution obj;

    vector<int> ans = obj.rightSideView(root);

    cout << "Right Side View: ";
    printVector(ans);

    // Expected Output:
    // Right Side View: 1 3 4

    return 0;
}