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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if (!root)
            return ans;
        map<int, int> mp;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while (!q.empty()) {
            auto it = q.front();
            int lvl = it.second;
            TreeNode* node = it.first;
            q.pop();

            if (mp.find(lvl) == mp.end()) {
                mp[lvl] = node->val;
            }

            if (node->right != NULL) {
                q.push({node->right, lvl + 1});
            }

            if (node->left != NULL) {
                q.push({node->left, lvl + 1});
            }
        }

        for (auto mpp : mp) {
            ans.push_back(mpp.second);
        }
        return ans;
    }
};