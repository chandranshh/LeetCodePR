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
    bool isCousins(TreeNode* root, int x, int y) {
        unordered_map<int, int> ump;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left) {
                    ump[node->left->val] = node->val;
                    q.push(node->left);
                }
                if (node->right) {
                    ump[node->right->val] = node->val;
                    q.push(node->right);
                }
            }
            if (ump.find(x) != ump.end() && ump.find(y) != ump.end() &&
                ump[x] != ump[y]) {
                return true;
            }
            ump.clear();
        }
        return false;
    }
};