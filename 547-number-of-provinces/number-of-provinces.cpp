class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(); 
        vector<vector<int>> adjList = convertToAdjList(isConnected);
        vector<bool> visited(n + 1, false); 
        int circleCount = 0; 

        for (int i = 1; i <= n; ++i) {
            if (!visited[i]) { 
                circleCount++; 
                dfs(i, visited, adjList); 
            }
        }

        return circleCount;
    }

private:
    vector<vector<int>> convertToAdjList(vector<vector<int>>& adjMatrix) {
        int n = adjMatrix.size();           
        vector<vector<int>> adjList(n + 1); 

        for (int i = 1; i <= n; ++i) { 
            for (int j = 1; j <= n; ++j) {
                if (adjMatrix[i - 1][j - 1] == 1 && i != j) { 
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }

        return adjList;
    }

    void dfs(int node, vector<bool>& visited, const vector<vector<int>>& adjList) {
        visited[node] = true;
        for (int neighbor : adjList[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, visited, adjList);
            }
        }
    }
};