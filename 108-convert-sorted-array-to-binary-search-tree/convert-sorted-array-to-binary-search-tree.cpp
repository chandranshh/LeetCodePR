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
    TreeNode* makeTree(int start, int end, vector<int>& nums) {
        if (start > end) {
            return NULL;
        }
        int mid = start + (end - start) / 2;
        TreeNode* newTree = new TreeNode(nums[mid]);
        newTree->left = makeTree(start, mid - 1, nums);
        newTree->right = makeTree(mid + 1, end, nums);
        return newTree;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int start = 0, end = nums.size() - 1;
        return makeTree(start, end, nums);
    }
};