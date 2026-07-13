#include <iostream>
#include <string>
using namespace std;

/*
============================================================
LeetCode 1022 - Sum of Root To Leaf Binary Numbers
Approach : Recursive DFS
Time Complexity : O(N * H)
Space Complexity : O(H^2)
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
    void sumRootToLeafHelper(TreeNode* root, int &sum, string binary) {
        if (!root)
            return;

        binary += (root->val + '0');

        if (!root->left && !root->right) {
            sum += stoi(binary, nullptr, 2);
            return;
        }

        sumRootToLeafHelper(root->left, sum, binary);
        sumRootToLeafHelper(root->right, sum, binary);
    }

public:
    int sumRootToLeaf(TreeNode* root) {
        int sum = 0;
        sumRootToLeafHelper(root, sum, "");
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