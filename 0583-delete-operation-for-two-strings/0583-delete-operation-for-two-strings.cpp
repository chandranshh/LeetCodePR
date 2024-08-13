class Solution {
public:
    int lcsHelper(string& s1, string& s2, int i, int j, vector<vector<int>>& dp) {
        if (i == 0 || j == 0) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        if (s1[i - 1] == s2[j - 1]) {
            dp[i][j] = 1 + lcsHelper(s1, s2, i - 1, j - 1, dp);
        } else {
            dp[i][j] = max(lcsHelper(s1, s2, i - 1, j, dp), lcsHelper(s1, s2, i, j - 1, dp));
        }

        return dp[i][j];
    }

    int minDistance(string word1, string word2) {
        int l1 = word1.size();
        int l2 = word2.size();
        vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1, -1));

        int lcs_count = lcsHelper(word1, word2, l1, l2, dp);

        return (l1 - lcs_count) + (l2 - lcs_count);
    }
};