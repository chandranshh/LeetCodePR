class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        if (n == 0)
            return mat;
        int m = mat[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] != 0) {
                    mat[i][j] = INT_MAX;
                    dfs(mat, i, j, n, m);
                }
            }
        }
        return mat;
    }

private:
    int dfs(vector<vector<int>>& mat, int i, int j, int n, int m) {
        if (i < 0 || i >= n || j < 0 || j >= m)
            return INT_MAX;

        if (mat[i][j] == INT_MAX) {
            mat[i][j] =
                min({dfs(mat, i + 1, j, n, m), dfs(mat, i - 1, j, n, m),
                     dfs(mat, i, j + 1, n, m), dfs(mat, i, j - 1, n, m)}) +
                1;
        }
        return mat[i][j];
    }
};