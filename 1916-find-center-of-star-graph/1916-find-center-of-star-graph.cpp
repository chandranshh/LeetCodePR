class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        if (n == 1)
            return 1; 

        vector<vector<int>> graph(
            n + 1); 
        vector<int> degree(n + 1,
                           0); 

        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }

        queue<int> q;
        for (int i = 1; i <= n; ++i) { 
            if (degree[i] == 1) {
                q.push(i);
            }
        }

        int ans = INT_MAX;
        while (!q.empty()) {
            int size = q.size();
            ans = INT_MAX;
            for (int i = 0; i < size; ++i) {
                int node = q.front();
                q.pop();
                ans = node;
                for (int neighbor : graph[node]) {
                    if (--degree[neighbor] == 1) {
                        q.push(neighbor);
                    }
                }
            }
        }

        return ans;
    }
};