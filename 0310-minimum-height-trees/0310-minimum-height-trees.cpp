class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};

        vector<vector<int>> graph(n);
        vector<int> degree(n, 0);


        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1];
            degree[u]++;
            degree[v]++;
        }

        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (degree[i] == 1) {
                q.push(i);
            }
        }
        
        vector<int> result;
        while (!q.empty()) {
            int size = q.size();
            result.clear(); // clear the result for the current level

            while (size--) {
                int node = q.front();
                q.pop();
                result.push_back(node); 

                for (int neighbor : graph[node]) {
                    if (--degree[neighbor] == 1) {
                        q.push(neighbor); // add the neighbor to the queue if it becomes a leaf
                    }
                }
            }
        }

        return result;
    }
};