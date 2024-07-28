class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<int>> dist(n, vector<int>(m, 0));

        vector<vector<int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

        queue<pair<pair<int, int>, int>> q; //<coordinates, steps>

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                }
            }
        }

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int x = q.front().first.first;
                int y = q.front().first.second;
                int steps = q.front().second;
                q.pop();
                dist[x][y] = steps;

                for (const auto& dir : dirs) {
                    int nx = x + dir[0];
                    int ny = y + dir[1];

                    if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
                        vis[nx][ny] == 0) {
                        vis[nx][ny] = 1;
                        q.push({{nx, ny}, steps + 1});
                    }
                }
            }
        }
        return dist;
    }
}; 