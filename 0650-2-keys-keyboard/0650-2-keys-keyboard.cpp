class Solution {
public:
    int helper(int n, bool isCopy, bool isPaste, int st, int copied, vector<vector<int>>& memo) {
        if (st == n) {
            return 0;
        }
        if (n <= 0 || st > n) {
            return 1001; 
        }
        if (memo[st][copied] != -1) {
            return memo[st][copied];
        }

        int copy = INT_MAX, paste = INT_MAX;
        if (!isCopy && st != copied) {
            copy = 1 + helper(n, true, false, st, st, memo);
        }
        if (copied > 0) {
            paste = 1 + helper(n, false, true, st + copied, copied, memo);
        }

        memo[st][copied] = min(copy, paste);
        return memo[st][copied];
    }

    int minSteps(int n) {
        if (n == 0 || n == 1) {
            return 0;
        }

        vector<vector<int>> memo(n + 1, vector<int>(n + 1, -1));
        return helper(n, false, false, 1, 0, memo);
    }
};