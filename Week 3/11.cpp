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

bool isSymmetricHelper(TreeNode *root_1, TreeNode *root_2) {
    if (root_1 == NULL && root_2 == NULL)
        return true;

    if (root_1 != NULL && root_2 != NULL) 
        return isSymmetricHelper(root_1->left, root_2->right) && isSymmetricHelper(root_1->right, root_2->left);
    
    return false;
}


bool isSymmetric(TreeNode *tree)
{
    return isSymmetricHelper(tree->left, tree->right);
}