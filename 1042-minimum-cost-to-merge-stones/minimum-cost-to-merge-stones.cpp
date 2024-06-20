class Solution {
public:
    int solve(vector<int>& stones, int start, int end, int breakSize, vector<int>& pre,
              vector<vector<int>>& dp) {
        // base condition
        if (start >= end) {
            return 0;
        }

        // check if the subproblem has already been evaluated
        if (dp[start][end] != -1) {
            return dp[start][end];
        }
        int ans = INT_MAX;
        for (int index = start; index < end; index += breakSize - 1) {
            int tmp = solve(stones, start, index, breakSize, pre, dp) +
                      solve(stones, index + 1, end, breakSize, pre, dp);
            ans = min(ans, tmp);
        }

        // check if they can be merged
        if ((end - start) % (breakSize - 1) == 0) {
            ans = ans + pre[end + 1] - pre[start];
        }
        return dp[start][end] = ans;
    }
    int mergeStones(vector<int>& stones, int breakSize) {
        int n = stones.size();
        if ((n - 1) % (breakSize - 1) != 0) {
            return -1;
        }
        // calculate the prefix sum
        vector<int> pre(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            pre[i] = pre[i - 1] + stones[i - 1];
        }

        // dp vector for memoization
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return solve(stones, 0, n - 1, breakSize, pre, dp);
    }
};