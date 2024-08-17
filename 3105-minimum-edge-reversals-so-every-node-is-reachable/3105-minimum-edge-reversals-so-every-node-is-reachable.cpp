class Solution {
    int dfs(int node, int parent, const vector<vector<pair<int, int>>>& graph, map<pair<int, int>, int>& dp) {
        int ans = 0;
        
        if (dp.find({node, parent}) != dp.end())
            return dp[{node, parent}];
        
        for (auto &neighbor : graph[node]) {
            int x = neighbor.first;
            int cost = neighbor.second;
            if (x != parent)
                ans += dfs(x, node, graph, dp) + cost;
        }
        
        return dp[{node, parent}] = ans;
    }
public:
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> graph(n);
        map<pair<int, int>, int> dp;
        
        for (auto x : edges) {
            graph[x[0]].push_back({x[1], 0});
            graph[x[1]].push_back({x[0], 1}); 
        }
        
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            ans.push_back(dfs(i, -1, graph, dp));
        }
        
        return ans;
    }
};