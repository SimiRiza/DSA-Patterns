#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
public:
    bool isChildSum(TreeNode* root) {
        if(!root) return true;

        int ls =0 , rs = 0;

        if(!root->left && !root->right)
        return true;

        if(root->left){
            ls =  root->left->val;
        } 
        if(root->right){
            rs = root->right->val;
        } 

        if(root->val == (ls + rs) && isChildSum(root->left) && isChildSum(root->right))
        return true;
        else
        return false;
    }
};

int main() {
    /*
            10
           /  \
          8    2
         / \    \
        3   5    2
    */

    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(8);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(2);

    Solution obj;

    if (obj.isChildSum(root))
        cout << "Child Sum Property Satisfied\n";
    else
        cout << "Child Sum Property Not Satisfied\n";

    return 0;
}