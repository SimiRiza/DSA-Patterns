#include <iostream>
using namespace std;

/*
============================================================
LeetCode 1022 - Sum of Root To Leaf Binary Numbers

Approach:
- Perform a DFS traversal.
- Carry the decimal value of the binary number formed so far.
- At each node:
      curr_sum = curr_sum * 2 + root->val;
- When a leaf is reached, add curr_sum to the final answer.

Time Complexity : O(N)
Space Complexity: O(H)

N = Number of nodes
H = Height of the tree
============================================================
*/

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
private:
    void sumRootToLeafHelper(TreeNode* root, int &sum, int curr_sum) {
        if (!root)
            return;

        // Shift previous bits left and append current bit.
        curr_sum = (curr_sum * 2) + root->val;

        if (!root->left && !root->right) {
            sum += curr_sum;
            return;
        }

        sumRootToLeafHelper(root->left, sum, curr_sum);
        sumRootToLeafHelper(root->right, sum, curr_sum);
    }

public:
    int sumRootToLeaf(TreeNode* root) {
        int sum = 0;
        sumRootToLeafHelper(root, sum, 0);
        return sum;
    }
};

int main() {
    /*
            1
           / \
          0   1
         / \ / \
        0  1 0  1

        Binary Numbers:
        100 = 4
        101 = 5
        110 = 6
        111 = 7

        Sum = 22
    */

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(0);
    root->right = new TreeNode(1);

    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(1);

    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(1);

    Solution obj;

    cout << "Sum of Root-to-Leaf Binary Numbers: "
         << obj.sumRootToLeaf(root) << endl;

    return 0;
}