class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL) {
            return ans;
        }
        map<int, map<int, multiset<int>>> nodes;
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});

        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            TreeNode* node = it.first;
            int hd = it.second.first;
            int lvl = it.second.second;

            nodes[hd][lvl].insert(node->val);

            if (node->left != NULL) {
                q.push({node->left, {hd - 1, lvl + 1}});
            }
            if (node->right != NULL) {
                q.push({node->right, {hd + 1, lvl + 1}});
            }
        }

        for (auto p : nodes) {
            vector<int> col;
            for (auto q : p.second) {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }

        return ans;
    }
};