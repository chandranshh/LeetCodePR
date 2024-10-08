class Solution {
public:
    int solve(int m, int n,  vector<vector<int>>&dp) {
        if (m < 0) {
            return 0;
        }
        if (n < 0) {
            return 0;
        }
        if (m == 0 && n == 0) {
            return 1;
        }

        if(dp[m][n]!=-1) return dp[m][n];

        int down = solve(m - 1, n, dp);
        int right = solve(m, n - 1, dp);

        return dp[m][n] =  down + right;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        int ans = solve(m - 1, n - 1, dp);

        return ans;
    }
}; 