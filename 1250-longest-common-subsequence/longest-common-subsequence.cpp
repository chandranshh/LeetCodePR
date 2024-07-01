class Solution {
public:
    int helper(int idx1, int idx2, string& text1, string& text2, vector<vector<int>>& dp) {
        // base case
        if (idx1 < 0 || idx2 < 0) {
            return 0;
        }
        // if already computed, return the stored value
        if (dp[idx1][idx2] != -1) {
            return dp[idx1][idx2];
        }
        // if current characters match
        if (text1[idx1] == text2[idx2]) {
            dp[idx1][idx2] = 1 + helper(idx1 - 1, idx2 - 1, text1, text2, dp);
        } else { // if they don't match
            dp[idx1][idx2] = max(helper(idx1, idx2 - 1, text1, text2, dp),
                                 helper(idx1 - 1, idx2, text1, text2, dp));
        }
        return dp[idx1][idx2];
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        // create a DP table initialized with -1
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return helper(n - 1, m - 1, text1, text2, dp);
    }
};
