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

TreeNode* Minimum(TreeNode *tree) {
    if (tree == NULL) 
        return NULL;
    
    while (tree->left != NULL)
        tree = tree->left;
    
    return tree;
}