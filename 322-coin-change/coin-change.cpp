class Solution {
public:
    int helper(int idx, vector<int>& coins, int amount,
               vector<vector<int>>& dp) {
        if (amount == 0)
            return 0;
        if (idx < 0 || amount < 0)
            return INT_MAX;

        if (dp[idx][amount] != -1)
            return dp[idx][amount];

        int notTake = helper(idx - 1, coins, amount, dp);

        int mini = INT_MAX;
        if (coins[idx] <= amount) {
            int take = helper(idx, coins, amount - coins[idx], dp);
            if (take != INT_MAX) {
                mini = min(mini, 1 + take);
            }
        }

        return dp[idx][amount] = min(mini, notTake);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int result = helper(n - 1, coins, amount, dp);

        return result == INT_MAX? -1 : result;
    }
};
