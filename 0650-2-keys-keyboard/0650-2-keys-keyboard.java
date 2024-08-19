class Solution {
    public int helper(int n, int st, int copied, int[][] dp) {
        if (st == n) {
            return 0;
        }
        if (st > n) {
            return 1001; 
        }
        if (dp[st][copied] != -1) {
            return dp[st][copied];
        }

        int copy = 1001, paste = 1001;
        if (st != copied) {
            copy = 1 + helper(n, st, st, dp);
        }
        if (copied > 0) {
            paste = 1 + helper(n, st + copied, copied, dp);
        }

        dp[st][copied] = Math.min(copy, paste);
        return dp[st][copied];
    }

    public int minSteps(int n) {
        if (n == 0 || n == 1) {
            return 0;
        }

        int[][] dp = new int[n + 1][n + 1];
        for (int[] row : dp) {
            Arrays.fill(row, -1);
        }
        return helper(n, 1, 0, dp);
    }
}