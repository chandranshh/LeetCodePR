class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> color(V, -1);
        
        for (int i = 0; i < V; i++) {
            if (color[i] == -1) {
                if (!bfs(graph, color, i)) {
                    return false;
                }
            }
        }
        return true;
    }

private:
    bool bfs(const vector<vector<int>>& graph, vector<int>& color, int start) {
        queue<int> q;
        color[start] = 0;
        q.push(start);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (const auto& neighbour : graph[node]) {
                if (color[neighbour] == color[node]) {
                    return false;
                } else if (color[neighbour] == -1) {
                    color[neighbour] = !color[node];
                    q.push(neighbour);
                }
            }
        }
        return true;
    }
};