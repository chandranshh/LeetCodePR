/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    TreeNode* bstToGst(TreeNode* root) {
        if (!root) {
            return nullptr;
        }
        int curr_sum = 0;
        
        bstToGstHelper(root, curr_sum);
        return root;
    }

    void bstToGstHelper(TreeNode* node, int& curr_sum) {
        if (!node) {
            return;
        }
        
      
        bstToGstHelper(node->right, curr_sum);
        
        
        int temp = node->val;
        node->val += curr_sum;
        curr_sum += temp;
        
        bstToGstHelper(node->left ,curr_sum);
    }
};