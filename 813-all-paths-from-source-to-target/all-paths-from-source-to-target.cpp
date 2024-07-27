class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> result; 
        vector<int> path; 
        vector<bool> visited(n, false); 
        dfs(0, n - 1, path, result, graph, visited); 
        return result;
    }

    void dfs(int node, int end, vector<int>& path, vector<vector<int>>& result,
             vector<vector<int>>& adj, vector<bool>& visited) {
        path.push_back(node); 
        visited[node] = true; 

        if (node == end) {
            result.push_back(path);
        } else {
            for (auto neighbour : adj[node]) {
                if (!visited[neighbour]) {
                    dfs(neighbour, end, path, result, adj, visited);
                }
            }
        }
        visited[node] = false;
        path.pop_back();
    }
};