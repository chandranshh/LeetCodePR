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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ans;

        if (!root)
            return {};

        q.push(root);
        bool right = true;

        while (!q.empty()) {
            int size = q.size();
            vector<int>levelElements(size);

            for(int i = 0; i < size; i++){
                TreeNode* node = q.front();
                q.pop();

                if(node->left){
                    q.push(node->left);
                }

                if(node->right){
                    q.push(node->right);
                }

                if(right){
                    levelElements[i] = node->val;
                    
                }else{
                    levelElements[size-i-1] = node->val;
                }
            }
            ans.push_back(levelElements);
            right = !right;
        }
        return ans;
    }
};