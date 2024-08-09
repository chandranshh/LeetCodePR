class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int size = s.size();
        vector<vector<int>> dp(size, vector<int>(size, -1));
        string s_rev = s;
        reverse(s_rev.begin(), s_rev.end());
        return lcs(s, s_rev, size - 1, size - 1, dp);
    }

private:
    int lcs(string s1, string s2, int i, int j, vector<vector<int>>& dp) {
        if (i < 0 || j < 0) {
            return 0;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        if (s1[i] == s2[j]) {
            dp[i][j] = 1 + lcs(s1, s2, i - 1, j - 1, dp);
        }else{
            dp[i][j] = max(lcs(s1, s2, i - 1, j, dp), lcs(s1, s2, i, j - 1, dp));
        }
        
        return dp[i][j];
    }
};