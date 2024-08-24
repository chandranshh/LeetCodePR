class Solution {
private:
    void helper(int n, int node, vector<vector<int>>& adj, vector<int>& path, vector<vector<int>>& ans) {
        if (node == n - 1) {
            ans.push_back(path);
            return;
        }

        for (const auto& neighbour : adj[node]) {
            path.push_back(neighbour);
            helper(n, neighbour, adj, path, ans);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> ans;
        vector<int> path;
        path.push_back(0); 
        helper(n, 0, graph, path, ans);
        return ans;
    }
};