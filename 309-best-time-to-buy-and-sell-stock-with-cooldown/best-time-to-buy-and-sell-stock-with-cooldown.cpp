class Solution {
public:
    int helper(int idx, int end, bool canBuy, vector<int>& prices,
               vector<vector<int>>& dp) {
        if (idx >= end) {
            return 0;
        }
        if (dp[idx][canBuy] != -1) {
            return dp[idx][canBuy];
        }
        int profit = 0;
        if (idx <= end) {
            if (canBuy) {
                int buy =
                    -prices[idx] + helper(idx + 1, end, false, prices, dp);
                int noBuy = helper(idx + 1, end, true, prices, dp);
                profit = max(buy, noBuy);
            } else {
                int sell = prices[idx] + helper(idx + 2, end, true, prices, dp);
                int noSell = helper(idx + 1, end, false, prices, dp);
                profit = max(sell, noSell);
            }
        }
        return dp[idx][canBuy] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int end = prices.size();
        vector<vector<int>> dp(end, vector<int>(2, -1));
        return helper(0, end, true, prices, dp);
    }
};
