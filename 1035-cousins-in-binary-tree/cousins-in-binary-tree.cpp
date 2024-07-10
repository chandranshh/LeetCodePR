class Solution {
    void dfs(TreeNode* root, int p, int x, int y, int d, vector<int>& depth,
             vector<int>& par) {
        if (!root)
            return;
        if (root->val == x || root->val == y) {
            depth.push_back(d);
            par.push_back(p);
        }
        dfs(root->left, root->val, x, y, d + 1, depth, par);
        dfs(root->right, root->val, x, y, d + 1, depth, par);
    }

public:
    bool isCousins(TreeNode* root, int x, int y) {
        vector<int> depth;
        vector<int> par;
        dfs(root, -1, x, y, 0, depth, par);
        return depth[0] == depth[1] && par[0] != par[1];
    }
};