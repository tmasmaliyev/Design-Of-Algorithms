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

int sumLeftHelper(TreeNode *tree, bool isAddable) {

    if (tree == NULL)
        return 0;

    if (tree->left == NULL && tree->right == NULL) {
        if (isAddable)
            return tree->val;
        
        return 0;
    }

    int left_sum = 0, right_sum = 0;

    left_sum = sumLeftHelper(tree->left, true);
    right_sum = sumLeftHelper(tree->right, false);

    return left_sum + right_sum;
}

int sumLeft(TreeNode *tree)
{
    return sumLeftHelper(tree, true);
}