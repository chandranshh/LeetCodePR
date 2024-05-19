class Solution {
public:
    int lcs(string s1, string s2, int m, int n) {
        int dp[m + 1][n + 1];

        // base condition
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 0;
                }
            }
        }

        // choice diagram
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[m][n];
    }


    int minInsertions(string s) {
        
        string rev = s;
        reverse(rev.begin(), rev.end());

        int len = s.length();

        return len - lcs(s, rev, len, len);

    }
};

// leetcode edocteel