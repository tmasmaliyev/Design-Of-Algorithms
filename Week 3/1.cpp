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

TreeNode *Find(TreeNode *tree, int element)
{
    if (tree == NULL)
        return NULL;
    
    if (tree->val < element)
        return Find(tree->right, element);
    
    else if (tree->val > element)
        return Find(tree->left, element);
    
    return tree;
}
