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

int maxDepth(TreeNode *tree)
{
    if (tree->left == NULL && tree->right == NULL)
        return 1;

    if (tree->left != NULL && tree->right != NULL) {
        int left = maxDepth(tree->left);
        int right = maxDepth(tree->right);

        int maxVal;

        if (left < right)
            maxVal = right;
        else 
            maxVal = left;
        
        return 1 + maxVal;
    }

    else if (tree->left != NULL && tree->right == NULL)
        return 1 + maxDepth(tree->left);
    
    else if (tree->left == NULL && tree->right != NULL)
        return 1 + maxDepth(tree->right);
}