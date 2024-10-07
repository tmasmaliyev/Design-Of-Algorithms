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

void InvertTreeNode(TreeNode*& tree) {
    if (tree == NULL)
        return;

    TreeNode *left = tree->left;
    TreeNode *right = tree->right;

    tree->left = right;
    tree->right = left;

    InvertTreeNode(tree->left);
    InvertTreeNode(tree->right);
}

TreeNode* Invert(TreeNode* tree)
{
    InvertTreeNode(tree);

    return tree;
}