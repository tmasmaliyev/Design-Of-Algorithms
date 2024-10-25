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

void PreOrder(TreeNode *tree)
{
    if (tree == NULL)
        return;
    
    printf("%d ", tree->val);

    PreOrder(tree->left);

    PreOrder(tree->right);
}