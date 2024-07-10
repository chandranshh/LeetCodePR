/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool traversal(TreeNode* root, int sum, int targetSum) {
        if (root == nullptr) {
            return false;
        }

        sum += root->val;

        if (sum == targetSum && root->left == nullptr &&
            root->right == nullptr) {
            return true;
        }

        return traversal(root->left, sum , targetSum) ||
               traversal(root->right, sum , targetSum);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        return traversal(root, 0, targetSum);
    }
};