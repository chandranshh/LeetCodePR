class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());
        int m = cuts.size();
        vector<vector<int>> dp(m, vector<int>(m, -1));
        return helper(0, n, cuts, 0, m - 1, dp);
    }

private:
    int helper(int left, int right, vector<int>& cuts, int start, int end, vector<vector<int>>& dp) {
        if (start > end) {
            return 0;
        }

        if (dp[start][end] != -1) {
            return dp[start][end];
        }

        int minCost = INT_MAX;

        for (int i = start; i <= end; ++i) {
            int cost = right - left;
            int leftCost = helper(left, cuts[i], cuts, start, i - 1, dp);
            int rightCost = helper(cuts[i], right, cuts, i + 1, end, dp);
            minCost = min(minCost, cost + leftCost + rightCost);
        }

        dp[start][end] = minCost;
        return minCost;
    }
};
