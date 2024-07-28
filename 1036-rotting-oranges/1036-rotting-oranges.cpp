class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        int fresh = 0;
        int time = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
                for (auto dir : dirs) {
                    int nx = x + dir[0];
                    int ny = y + dir[1];
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1) {
                        grid[nx][ny] = 2;
                        q.push({nx, ny});
                        fresh--;
                    }
                }
            }
            if (!q.empty()) {
                time++;
            }
        }

        return fresh == 0 ? time : -1;
    }
};