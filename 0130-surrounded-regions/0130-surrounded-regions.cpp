class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty())
            return;

        int m = board.size();
        int n = board[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if ((i == 0 || i == m - 1 || j == 0 || j == n - 1) &&
                    board[i][j] == 'O') {
                    q.push({i, j});
                }
            }
        }

        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            board[x][y] = '-';

            for (const auto& dir : dirs) {
                int nx = x + dir[0];
                int ny = y + dir[1];

                if (nx >= 0 && nx < m && ny >= 0 && ny < n &&
                    board[nx][ny] == 'O') {
                    q.push({nx, ny});
                    board[nx][ny] = '-';
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == '-') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};
// class Solution {
// public:
//     void solve(vector<vector<char>>& board) {
//         int m = board.size();
//         int n = board[0].size();

//         queue<pair<int,int>>q;
//         vector<vector<int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
//         for (int i = 1; i < m - 1; i++) {
//             for (int j = 1; j < n - 1; j++) {
//                 if (board[i][j] == 'O') {
//                     q.push({i, j});
//                 }
//             }
//         }

//         while (!q.empty()) {
//             int size = q.size();
//             while (size--) {
//                 int x = q.front().first;
//                 int y = q.front().second;
//                 q.pop();

//                 for (const auto& dir : dirs) {
//                     int nx = x + dir[0];
//                     int ny = y + dir[1];

//                     if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
//                         board[nx][ny] == 'X') {
//                         board[x][y] = 'X';
//                     }
//                 }
//             }
//         }
//     }
// };