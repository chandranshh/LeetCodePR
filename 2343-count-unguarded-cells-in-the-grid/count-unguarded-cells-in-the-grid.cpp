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

        for (auto& guard : guards) {
            int x = guard[0], y = guard[1];
            for (auto [dx, dy] : directions) {
                int nx = x + dx, ny = y + dy;
                while (nx >= 0 && nx < m && ny >= 0 && ny < n &&
                       grid[nx][ny] != 'W' && grid[nx][ny] != 'G') {
                    if (grid[nx][ny] == '.') {
                        guarded[nx][ny] = true;
                    }
                    nx += dx;
                    ny += dy;
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