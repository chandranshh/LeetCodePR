class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<int> adj[numCourses];
        for (auto node : prerequisites) {
            adj[node[1]].push_back(node[0]);
        }

        vector<int>indegree(numCourses, 0);

        for (int node = 0; node < numCourses; node++) {
            for (auto neighbour : adj[node]) {
                indegree[neighbour]++;
            }
        }

        queue<int> q;
        for (int node = 0; node < numCourses; node++) {
            if (indegree[node] == 0) {
                q.push(node);
            }
        }

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto node = q.front();
                q.pop();
                for (auto neighbours : adj[node]) {
                    indegree[neighbours]--;
                    if (indegree[neighbours] == 0) {
                        q.push(neighbours);
                    }
                }
            }
        }

        for (int node = 0; node < numCourses; node++) {
            if (indegree[node] != 0) {
                return false;
            }
        }

        return true;
    }
};