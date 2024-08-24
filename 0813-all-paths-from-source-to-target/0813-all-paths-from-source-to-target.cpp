class Solution {
private:
    void helper(int n, int node, vector<vector<int>>& adj, vector<int>& path, vector<vector<int>>& ans, vector<bool>& vis) {
        if (node == n - 1) {
            ans.push_back(path);
            return;
        }

        for (const auto& neighbour : adj[node]) {
            if (!vis[neighbour]) {
                vis[neighbour] = true;
                path.push_back(neighbour);
                helper(n, neighbour, adj, path, ans, vis);
                path.pop_back();
                vis[neighbour] = false;
            }
        }
    }

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> ans;
        vector<int> path;
        vector<bool> vis(n, false);
        
        path.push_back(0); 
        vis[0] = true; 
        helper(n, 0, graph, path, ans, vis);
        return ans;
    }
};