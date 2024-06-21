class Solution {
public:
    int helper(int idx, int end, int cnt, int k, bool canBuy,
               vector<int>& prices, vector<vector<vector<int>>>& dp) {
        if (idx >= end || cnt >= k) {
            return 0;
        }
        if (dp[idx][cnt][canBuy] != -1) {
            return dp[idx][cnt][canBuy];
        }
        int profit = 0;
        if (canBuy) {
            int buy =
                -prices[idx] + helper(idx + 1, end, cnt, k, false, prices, dp);
            int noBuy = helper(idx + 1, end, cnt, k, true, prices, dp);
            profit = max(buy, noBuy);
        } else {
            int sell = prices[idx] +
                       helper(idx + 1, end, cnt + 1, k, true, prices, dp);
            int noSell = helper(idx + 1, end, cnt, k, false, prices, dp);
            profit = max(sell, noSell);
        }
        return dp[idx][cnt][canBuy] = profit;
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(k+1, vector<int>(2, -1)));
        return helper(0, n, 0, k, true, prices, dp);
    }
};