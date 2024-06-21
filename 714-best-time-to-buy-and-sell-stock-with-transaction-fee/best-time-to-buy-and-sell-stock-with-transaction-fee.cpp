class Solution {
public:
    int helper(int idx, int end, bool canBuy, vector<int>& prices, int fee,
               vector<vector<int>>& dp) {
        if (idx == end) {
            return 0;
        }
        if (dp[idx][canBuy] != -1) {
            return dp[idx][canBuy];
        }
        int profit = 0;
        if (canBuy) {
            int buy =
                -prices[idx] + helper(idx + 1, end, false, prices, fee, dp);
            int noBuy = helper(idx + 1, end, true, prices, fee, dp);
            profit = max(buy, noBuy);
        } else {
            int sell =
                prices[idx] - fee + helper(idx + 1, end, true, prices, fee, dp);
            int noSell = helper(idx + 1, end, false, prices, fee, dp);
            profit = max(sell, noSell);
        }
        return dp[idx][canBuy] = profit;
    }

    int maxProfit(vector<int>& prices, int fee) {
        int end = prices.size();
        vector<vector<int>> dp(end, vector<int>(2, -1));
        return helper(0, end, true, prices, fee, dp);
    }
};
