class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards,
                       vector<vector<int>>& walls) {
        vector<vector<char>> grid(m, vector<char>(n, '.'));

        for (auto& guard : guards) {
            grid[guard[0]][guard[1]] = 'G';
        }
        for (auto& wall : walls) {
            grid[wall[0]][wall[1]] = 'W';
        }

        vector<vector<bool>> guarded(m, vector<bool>(n, false));

        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        queue<pair<int, int>> q;
        for (auto& guard : guards) {
            q.push({guard[0], guard[1]});
        }

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (auto [dx, dy] : directions) {
                int nx = x + dx, ny = y + dy;
                queue<pair<int, int>> dirQueue;
                dirQueue.push({nx, ny});

                while (!dirQueue.empty()) {
                    auto [cx, cy] = dirQueue.front();
                    dirQueue.pop();

                    if (cx >= 0 && cx < m && cy >= 0 && cy < n &&
                        grid[cx][cy] != 'W' && grid[cx][cy] != 'G') {
                        if (grid[cx][cy] == '.') {
                            guarded[cx][cy] = true;
                            dirQueue.push({cx + dx, cy + dy});
                        }
                    } else {
                        break;
                    }
                }
            }
        }

        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '.' && !guarded[i][j]) {
                    count++;
                }
            }
        }

        return count;
    }
};