#include <stdio.h>

class TreeNode {
    public:
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) {
            val = x;
            left = NULL;
            right = NULL;
        }
};

int abs(int x, int y) {
    int res = x - y;

    if (res < 0)
        return -res;

    return res;
}

int assignMaxDepthToNode(TreeNode*& root) {
    if (root == NULL)    
        return 0;

    int left = assignMaxDepthToNode(root->left);
    int right = assignMaxDepthToNode(root->right);

    int maxVal;

    if (left < right)
        maxVal = right;
    else
        maxVal = left;
    
    root->val = 1 + maxVal;

    return 1 + maxVal;
}

bool isBalancedHelper(TreeNode* root) {

    if (root->left == NULL && root->right == NULL)
        return true;

    else if (root->left != NULL && root->right == NULL) {
        if (root->left->val > 1)
            return false;
        
        return true;
    }
    else if (root->left == NULL && root->right != NULL) {
        if (root->right->val > 1)
            return false;
        
        return true;
    }
    bool left = isBalancedHelper(root->left);
    bool right = isBalancedHelper(root->right);

    if (abs(root->left->val, root->right->val) > 1)
        return false;

    return left && right;
}

bool isBalanced(TreeNode* root)
{
    assignMaxDepthToNode(root);

    return isBalancedHelper(root);   
}
