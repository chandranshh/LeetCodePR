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
    int getMax(TreeNode* root, int& maxsum) {

        if (root == NULL) {
            return 0;
        }

        int leftval = max(0, getMax(root->left, maxsum));
        int rightval = max(0, getMax(root->right, maxsum));

        int currSum = root->val + leftval + rightval;
        maxsum = max(maxsum, currSum);
        return root->val + max(leftval, rightval);
    }
    int maxPathSum(TreeNode* root) {
        int maxsum = INT_MIN;
        getMax(root, maxsum);
        return maxsum;
    }
};