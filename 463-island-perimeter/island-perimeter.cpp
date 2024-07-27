class Solution {
private:
    int dfs(int row, int col, vector<vector<int>>& vis, vector<vector<int>>& grid) {
        vis[row][col] = 1;
        int n = grid.size();
        int m = grid[0].size();
        int perimeter = 0;
        //all four possible directions (up, down, left, right)
        int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (auto& dir : directions) {
            int nrow = row + dir[0];
            int ncol = col + dir[1];
            //the neighbor is out of bounds or water, increment the perimeter
            if (nrow < 0 || nrow >= n || ncol < 0 || ncol >= m || grid[nrow][ncol] == 0) {
                perimeter++;
            }
            //the neighbor is land and unvisited, recursively call dfs
            else if (grid[nrow][ncol] == 1 && !vis[nrow][ncol]) {
                perimeter += dfs(nrow, ncol, vis, grid);
            }
        }
        return perimeter;
    }

public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int perimeter = 0;

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if (!vis[row][col] && grid[row][col] == 1) {
                    perimeter = dfs(row, col, vis, grid);
                    return perimeter;
                }
            }
        }
        return perimeter;
    }
};
