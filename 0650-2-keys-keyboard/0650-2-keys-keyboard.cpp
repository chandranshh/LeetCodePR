//tabulation
class Solution {
public:
    int minSteps(int n) {
        if (n == 0 || n == 1) {
            return 0;
        }

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 1001));
        
        dp[1][0] = 0;
        dp[1][1] = 1;

        for (int st = 1; st <= n; ++st) {
            for (int copied = 0; copied <= n; ++copied) {
                if (dp[st][copied] != 1001) {
                    if (st != copied) {
                        dp[st][st] = min(dp[st][st], dp[st][copied] + 1);
                    }
                    if (copied > 0 && st + copied <= n) {
                        dp[st + copied][copied] = min(dp[st + copied][copied], dp[st][copied] + 1);
                    }
                }
            }
        }

        int result = 1001;
        for (int copied = 0; copied <= n; ++copied) {
            result = min(result, dp[n][copied]);
        }

        return result;
    }
};

//recursion + dp
// class Solution {
// public:
//     int helper(int n, int st, int copied, vector<vector<int>>& dp) {
//         if (st == n) {
//             return 0;
//         }
//         if (st > n) {
//             return 1001; 
//         }
//         if (dp[st][copied] != -1) {
//             return dp[st][copied];
//         }

//         int copy = 1001, paste = 1001;
//         if (st != copied) {
//             copy = 1 + helper(n, st, st, dp);
//         }
//         if (copied > 0) {
//             paste = 1 + helper(n, st + copied, copied, dp);
//         }

//         dp[st][copied] = min(copy, paste);
//         return dp[st][copied];
//     }

//     int minSteps(int n) {
//         if (n == 0 || n == 1) {
//             return 0;
//         }

//         vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
//         return helper(n, 1, 0, dp);
//     }
// };