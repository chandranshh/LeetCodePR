class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> indegree(n, 0);
        vector<vector<int>> graph(n);

        for (int i = 0; i < n; ++i) {
            if (leftChild[i] != -1) {
                indegree[leftChild[i]]++;
                graph[i].push_back(leftChild[i]);
            }
            if (rightChild[i] != -1) {
                indegree[rightChild[i]]++;
                graph[i].push_back(rightChild[i]);
            }
        }

        int rootCount = 0;
        int root = -1;

        for (int i = 0; i < n; ++i) {
            if (indegree[i] == 0) {
                rootCount++;
                root = i;
            } else if (indegree[i] > 1) {
                return false; 
            }
        }

        if (rootCount != 1) return false; 

        queue<int> q;
        vector<bool> visited(n, false);
        q.push(root);
        visited[root] = true;
        int visitedCount = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            visitedCount++;

            for (int neighbor : graph[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        return visitedCount == n; 
    }
};