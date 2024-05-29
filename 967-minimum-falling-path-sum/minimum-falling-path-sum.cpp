class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int j = 0; j < n; j++) {
            dp[0][j] = matrix[0][j];
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int down = matrix[i][j] + dp[i - 1][j];
                int diagDown = matrix[i][j] + (j + 1 < n ? dp[i - 1][j + 1] : 1e9);
                int diagUp = matrix[i][j] + (j - 1 >= 0 ? dp[i - 1][j - 1] : 1e9);
                dp[i][j] = min(down, min(diagDown, diagUp));
            }
        }

        int minVal = INT_MAX;
        for (int j = 0; j < n; j++) {
            minVal = min(minVal, dp[n - 1][j]);
        }

        return minVal;
    }
};