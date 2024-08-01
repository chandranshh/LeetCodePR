class Solution {
private:
    bool dfs(int node, int col, vector<int>& color,
             const vector<vector<int>>& graph) {
        color[node] = col;

        for (const auto& neighbour : graph[node]) {
            if (color[neighbour] == color[node]) {
                return false;
            } else if (color[neighbour] == -1) {
                if (dfs(neighbour, !col, color, graph) == false) {
                    return false;
                }
            }
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> color(V, -1);

        for (int i = 0; i < V; i++) {
            if (color[i] == -1) {
                if (dfs(i, 0, color, graph) == false) {
                    return false;
                }
            }
        }
        return true;
    }
};