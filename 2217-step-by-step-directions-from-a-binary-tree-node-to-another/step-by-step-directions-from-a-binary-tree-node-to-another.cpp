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
    TreeNode* LCA(TreeNode* root, int x, int y) {
        if (root == NULL || root->val == x || root->val == y)
            return root;
        TreeNode* l = LCA(root->left, x, y);
        TreeNode* r = LCA(root->right, x, y);
        if (l == NULL)
            return r;
        if (r == NULL)
            return l;
        return root;
    }
    bool dfs(TreeNode* root, int x, string& path, bool reverse) {
        if (root == NULL)
            return 0;
        if (root->val == x)
            return 1;

        path += (reverse ? 'U' : 'L');
        if (dfs(root->left, x, path, reverse))
            return 1;
        path.pop_back();

        path += (reverse ? 'U' : 'R');
        if (dfs(root->right, x, path, reverse))
            return 1;
        path.pop_back();

        return 0;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        root = LCA(root, startValue, destValue);
        string pathFrom = "", pathTo = "";
        dfs(root, startValue, pathFrom, 1);
        dfs(root, destValue, pathTo, 0);
        return pathFrom + pathTo;
    }
};