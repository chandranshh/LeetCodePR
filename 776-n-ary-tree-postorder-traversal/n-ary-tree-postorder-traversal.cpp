class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> result;
        postorderHelper(root, result);
        return result;
    }

private:
    void postorderHelper(Node* node, vector<int>& result) {
        if (node == nullptr) {
            return;
        }

        for (Node* child : node->children) {
            postorderHelper(child, result);
        }
        result.push_back(node->val);
    }
};