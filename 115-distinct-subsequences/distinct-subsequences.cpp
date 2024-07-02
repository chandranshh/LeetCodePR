class Solution {
public:
    int helper(string& s, string& t, int idx1, int idx2, vector<vector<int>>& dp) {
        // Base cases
        if (idx2 < 0) {
            return 1;  // All characters of t have been matched
        }
        if (idx1 < 0) {
            return 0;  // s is exhausted but t is not fully matched
        }

        // If the result for this state has already been calculated, return it
        if (dp[idx1][idx2] != -1) {
            return dp[idx1][idx2];
        }

        // If the characters at the current positions match
        if (s[idx1] == t[idx2]) {
            dp[idx1][idx2] = helper(s, t, idx1 - 1, idx2 - 1, dp) + helper(s, t, idx1 - 1, idx2, dp);
        } else {
            // If the characters don't match, we can only exclude the current character of s
            dp[idx1][idx2] = helper(s, t, idx1 - 1, idx2, dp);
        }

        return dp[idx1][idx2];
    }

    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return helper(s, t, m - 1, n - 1, dp);
    }
};