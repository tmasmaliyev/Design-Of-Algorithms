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

TreeNode* Next(TreeNode *tree) {
    if (tree == NULL)
       return NULL;

    int init_node_val = tree->val;

    if (tree->right != NULL) {
        tree = tree->right;

        while (tree->left != NULL)
            tree = tree->left;
        
        return tree;
    }
    else if (tree->parent == NULL)
        return NULL;

    else if (tree->parent->left == tree)
        return tree->parent;
    
    else {
        bool hasNext = false;

        while (tree->parent != NULL) {
            if (tree->parent->right != tree) {
                hasNext = true;
                break;
            }
            tree = tree->parent;
        }

        if (hasNext)
            return tree->parent;
    }

    return NULL;
}
