//bottom-up dp

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == 1 && j == 1) {
                    dp[i][j] = 1;
                } else {
                    if (i > 1) {
                        dp[i][j] += dp[i - 1][j];
                    }
                    if (j > 1) {
                        dp[i][j] += dp[i][j - 1];
                    }
                }
            }
        }
        return dp[m][n];
    }
};
