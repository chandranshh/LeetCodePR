class Solution {
    int dfs(int node, int parent, const vector<vector<pair<int, int>>>& graph) {
        int ans = 0;
        
        for (auto &neighbor : graph[node]) {
            int x = neighbor.first;
            int cost = neighbor.second;
            if (x != parent)
                ans += dfs(x, node, graph) + cost;
        }
        
        return ans;
    }
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> graph(n);
        
        for (auto x : connections) {
            graph[x[0]].push_back({x[1], 1}); 
            graph[x[1]].push_back({x[0], 0}); 
        }
        
        return dfs(0, -1, graph);
    }
};