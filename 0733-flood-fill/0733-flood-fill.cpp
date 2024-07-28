class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        queue<pair<int, int>> q;
        
        int start = image[sr][sc];

        if (start == color) {
            return image;
        }

        q.push({sr, sc});
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        visited[sr][sc] = true; 
        image[sr][sc] = color; 

        vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                for (const auto& dir : dirs) {
                    int nx = x + dir[0];
                    int ny = y + dir[1];

                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && 
                        image[nx][ny] == start && !visited[nx][ny]) {
                        image[nx][ny] = color;
                        visited[nx][ny] = true; 
                        q.push({nx, ny});
                    }
                }
            }
        }
        return image;
    }
};