class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        vector<int> adj[numCourses];
        for (auto node : prerequisites) {
            adj[node[1]].push_back(node[0]);
        }

        vector<int> indegree(numCourses, 0);
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
        vector<int> ans;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto node = q.front();
                q.pop();
                ans.push_back(node);
                for (auto neighbour : adj[node]) {
                    indegree[neighbour]--;
                    if (indegree[neighbour] == 0) {
                        q.push(neighbour);
                    }
                }
            }
        }
        // return ans iff the topological sort is valid
        if (ans.size() == numCourses) {
            return ans;
        } else {
            return {}; // if not (if there is/are cycle(s)) then return an empty vector 
        }
    }
};