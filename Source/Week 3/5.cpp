#include <stdio.h>

class TreeNode {
    public:
        int val;
        TreeNode *left, *right, *parent;
        TreeNode(int x, TreeNode *prev) {
            val = x;
            left = NULL;
            right = NULL;
            parent = prev;
        }
};

TreeNode *Prev(TreeNode *tree)
{
    if (tree == NULL)
        return NULL;
    
    if (tree->left != NULL) {
        tree = tree->left;

        while (tree->right != NULL)
            tree = tree->right;

        return tree;
    }

    else if (tree->parent == NULL)
        return NULL;
 
    else if (tree->parent->right == tree)
        return tree->parent; 
    
    else {
        bool hasPrevious = false;

        while (tree->parent != NULL) {
            if (tree->parent->left != tree) {
                hasPrevious = true;
                break;
            }
            tree = tree->parent;
        }

        if (hasPrevious)
            return tree->parent;
    }

    return NULL;
}