class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        if (!root || !target) return ans;

        // step 1: find the parent of each node using bfs
        unordered_map<TreeNode*, TreeNode*> parent;
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node->left) {
                parent[node->left] = node;
                q.push(node->left);
            }
            if (node->right) {
                parent[node->right] = node;
                q.push(node->right);
            }
        }

        // step 2: bfs to find nodes at distance k from target
        unordered_map<TreeNode*, int> visited;
        q.push(target);
        visited[target] = 1;
        int current_distance = 0;

        while (!q.empty()) {
            int size = q.size();
            if (current_distance == k) {
                for (int i = 0; i < size; ++i) {
                    TreeNode* node = q.front();
                    q.pop();
                    ans.push_back(node->val);
                }
                return ans;
            }
            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left && !visited[node->left]) {
                    q.push(node->left);
                    visited[node->left] = 1;
                }
                if (node->right && !visited[node->right]) {
                    q.push(node->right);
                    visited[node->right] = 1;
                }
                if (parent[node] && !visited[parent[node]]) {
                    q.push(parent[node]);
                    visited[parent[node]] = 1;
                }
            }
            current_distance++;
        }

        return ans;
    }
};