/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool findPath(TreeNode* root, TreeNode* target, vector<TreeNode*>& path) {
        if (root == NULL) {
            return false;
        }
        
        path.push_back(root);

        if (root == target) {
            return true;
        }
        
        if ((root->left && findPath(root->left, target, path)) || 
            (root->right && findPath(root->right, target, path))) {
            return true;
        }
        
        path.pop_back();
        return false;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pathP, pathQ;
        
        if (!findPath(root, p, pathP) || !findPath(root, q, pathQ)) {
            return NULL;
        }

        int i = 0;
        while (i < pathP.size() && i < pathQ.size() && pathP[i] == pathQ[i]) {
            i++;
        }
        return pathP[i - 1];
    }
};