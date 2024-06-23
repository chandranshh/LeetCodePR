class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (root == NULL) {
            return true;
        }

        int leftHeight = getTreeHeight(root->left);
        int rightHeight = getTreeHeight(root->right);

        if (abs(leftHeight - rightHeight) > 1) {
            return false;
        }

        return isBalanced(root->left) && isBalanced(root->right);
    }

    int getTreeHeight(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        int leftHeight = 1 + getTreeHeight(root->left);
        int rightHeight = 1 + getTreeHeight(root->right);

        return max(leftHeight, rightHeight);
    }
};