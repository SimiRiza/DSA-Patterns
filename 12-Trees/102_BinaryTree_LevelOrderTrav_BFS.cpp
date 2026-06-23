/*
Approach:
- Use BFS (Level Order Traversal).
- Store current queue size to process one level at a time.
- Push all nodes of the current level into a vector.
- Add children to queue for next level.

Time Complexity: O(N)
Space Complexity: O(N)
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
    TreeNode(int x, TreeNode *l, TreeNode *r) : val(x), left(l), right(r) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr)
            return {};

        queue<TreeNode*> q;
        vector<vector<int>> res;

        q.push(root);

        while(!q.empty()) {
            int x = q.size();
            vector<int> arr;

            for(int i = 0; i < x; i++) {
                arr.push_back(q.front()->val);

                if(q.front()->left)
                    q.push(q.front()->left);

                if(q.front()->right)
                    q.push(q.front()->right);

                q.pop();
            }

            res.push_back(arr);
        }

        return res;
    }
};

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution obj;
    vector<vector<int>> ans = obj.levelOrder(root);

    for(auto &level : ans) {
        for(int x : level)
            cout << x << " ";
        cout << endl;
    }

    return 0;
}