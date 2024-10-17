#include <stdio.h>
#include <iostream>

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

int minDepth(TreeNode *tree)
{
    if (tree->left == NULL && tree->right == NULL)
        return 1;

    if (tree->left != NULL && tree->right != NULL) {
        int left = minDepth(tree->left);
        int right = minDepth(tree->right);

        int minVal;

        if (left < right)
            minVal = left;
        else 
            minVal = right;
        
        return 1 + minVal;
    }

    else if (tree->left != NULL && tree->right == NULL)
        return 1 + minDepth(tree->left);
    
    else if (tree->left == NULL && tree->right != NULL)
        return 1 + minDepth(tree->right);
}