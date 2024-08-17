class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> graph(n);

        for (auto& connection : connections) {
            int u = connection[0];
            int v = connection[1];
            graph[u].push_back({v, 1});
            graph[v].push_back({u, 0});
        }

        queue<pair<int, int>> q;
        q.push({0, 0});
        vector<bool> vis(n, false);
        int ans = 0;

        while (!q.empty()) {
            auto current = q.front();
            q.pop();

            int node = current.first;
            int reversals = current.second;

            vis[node] = true;
            ans += reversals;

            for (auto& neighbor : graph[node]) {
                int neighborNode = neighbor.first;
                int neighborReversals = neighbor.second;

                if (!vis[neighborNode]) {
                    q.push({neighborNode, neighborReversals});
                }
            }
        }

        return ans;
    }
};