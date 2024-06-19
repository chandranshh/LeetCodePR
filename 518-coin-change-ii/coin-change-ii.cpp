class Solution {
public:
    int helper(int idx, int amount, vector<int>& coins, int n,
               vector<vector<int>>& dp) {
        if (amount == 0) {
            return 1;
        }
        if (idx >= n || amount < 0) {
            return 0;
        }
        if (dp[idx][amount] != -1) {
            return dp[idx][amount];
        }

        int noTake = helper(idx + 1, amount, coins, n, dp);
        int take = 0;
        if (coins[idx] <= amount) {
            take = helper(idx, amount - coins[idx], coins, n, dp);
        }

        dp[idx][amount] = take + noTake;
        return dp[idx][amount];
    }
    
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));
        return helper(0, amount, coins, n, dp);
    }
};
