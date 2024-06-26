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
    void inOrder(TreeNode* root, vector<int>& vec) {
        if (!root)
            return;

        inOrder(root->left, vec);
        vec.push_back(root->val);
        inOrder(root->right, vec);
    }

    TreeNode* makeBST(int left, int right, vector<int>& vec) {
        if (left > right)
            return NULL;

        int mid = left + (right - left) / 2;
        TreeNode* root = new TreeNode(vec[mid]);

        root->left = makeBST(left, mid - 1, vec);
        root->right = makeBST(mid + 1, right, vec);

        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> vec;
        inOrder(root, vec);
        int left = 0, right = vec.size() - 1;

        return makeBST(left, right, vec);
    }
};
;