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
    int minDepth(TreeNode* root) {
        if (!root)
            return 0; 

        return helper(root);
    }
    
    int helper(TreeNode* root) {
       
        if (!root->left && !root->right) {
            return 1; 
        }
        
        int left_depth = INT_MAX, right_depth = INT_MAX;
        
        if (root->left) {
            left_depth = helper(root->left);
        }
        
        if (root->right) {
            right_depth = helper(root->right);
        }
        
        // return the minimum depth of the subtree rooted at 'root'
        return 1 + min(left_depth, right_depth);
    }
};
