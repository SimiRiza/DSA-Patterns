/*
 * Problem:
 * LeetCode 100 - Same Tree
 *
 * Approach:
 * 1. If both nodes are null, they are identical.
 * 2. If only one node is null, the trees are different.
 * 3. If node values differ, return false.
 * 4. Recursively compare the left and right subtrees.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(h)
 * (h = height of the tree due to recursion stack)
 */

#include <iostream>
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q)
            return true;

        // One tree has a node while the other doesn't
        if ((p == nullptr && q != nullptr) || (p != nullptr && q == nullptr))
            return false;

        // Current node values are different
        if (p->val != q->val)
            return false;

        // Recursively compare left and right subtrees
        bool left_iden = isSameTree(p->left, q->left);
        bool ryt_iden = isSameTree(p->right, q->right);

        return left_iden && ryt_iden;
    }
};

int main() {
    // Tree 1
    //      1
    //     / \
    //    2   3
    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);

    // Tree 2
    //      1
    //     / \
    //    2   3
    TreeNode* q = new TreeNode(1);
    q->left = new TreeNode(2);
    q->right = new TreeNode(3);

    Solution obj;

    if (obj.isSameTree(p, q))
        cout << "Trees are identical." << endl;
    else
        cout << "Trees are not identical." << endl;

    // Expected Output:
    // Trees are identical.

    return 0;
}