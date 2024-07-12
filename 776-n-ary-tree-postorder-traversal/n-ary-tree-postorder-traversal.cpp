/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> result;
        if (root == nullptr) {
            return result;
        }

        stack<Node*> stk;
        stk.push(root);

        while (!stk.empty()) {
            Node* node = stk.top();
            stk.pop();
            
            result.push_back(node->val);
            
            for (int i = 0; i < node->children.size(); i++) {
                stk.push(node->children[i]);
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};