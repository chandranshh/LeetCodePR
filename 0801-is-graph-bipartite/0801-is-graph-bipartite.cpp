class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> color(V, -1);
        for (int i = 0; i < V; i++) {
            if (color[i] == -1) {
                queue<int> q;
                color[i] = 0;
                q.push(i);

                while (!q.empty()) {
                    int size = q.size();
                    while (size--) {
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
                }
            }
        }
        return true;
    }
};

/*
int n = graph.size();
        vector<int> color(n, -1); // -1: uncolored, 0: color 1, 1: color 2

        for (int start = 0; start < n; ++start) {
            if (color[start] == -1) {
                queue<int> q;
                q.push(start);
                color[start] = 0;

                while (!q.empty()) {
                    int node = q.front();
                    q.pop();
                    for (int neighbor : graph[node]) {
                        if (color[neighbor] == -1) {
                            color[neighbor] = 1 - color[node];
                            q.push(neighbor);
                        } else if (color[neighbor] == color[node]) {
                            return false;
                            // Conflict, not bipartite
                        }
                    }
                }
            }
        }
        return true;
*/