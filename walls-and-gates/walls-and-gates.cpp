#include <bits/stdc++.h> 
vector<vector<int>> wallsAndGates(vector<vector<int>> &a, int n, int m) {
    vector<vector<int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    queue<pair<pair<int, int>, int>> q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 0) {
                q.push({{i, j}, 0});
            }
        }
    }

    while (!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int steps = q.front().second;
        q.pop();

        for (const auto& dir : dirs) {
            int nx = x + dir[0];
            int ny = y + dir[1];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && a[nx][ny] == INT_MAX) {
                a[nx][ny] = steps + 1;
                q.push({{nx, ny}, steps + 1});
            }
        }
    }
    return a;
}
