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

    int minDistance(string word1, string word2) {
        int l1 = word1.size();
        int l2 = word2.size();

        int del = -1;
        int ins = -1;

        int lcs_count = lcs(word1, word2, l1, l2);

        if (l1 > l2) {
            del = l1 - lcs_count;
            ins = l2 - lcs_count;
        } else {
            ins = l1 - lcs_count;
            del = l2 - lcs_count;
        }

        return del + ins;
    }
};