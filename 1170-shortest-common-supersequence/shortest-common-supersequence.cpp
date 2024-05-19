class Solution {
public:
    string scs(string s1, string s2, int m, int n) {

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 0;
                }
            }
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        int i = m, j = n;
        string scs = "";

        while (i > 0 && j > 0) {
            if (s1[i - 1] == s2[j - 1]) {
                scs.push_back(s1[i - 1]);
                i--;
                j--;
            } else if (dp[i - 1][j] > dp[i][j - 1]) {
                scs.push_back(s1[i - 1]);
                i--;
            } else {
                scs.push_back(s2[j - 1]);
                j--;
            }
        }

        while (i > 0) {
            scs.push_back(s1[i - 1]);
            i--;
        }
        while (j > 0) {
            scs.push_back(s2[j - 1]);
            j--;
        }

        reverse(scs.begin(), scs.end());

        return scs;
    }

    string shortestCommonSupersequence(string str1, string str2) {

        int l1 = str1.length(), l2 = str2.length();
        return scs(str1, str2, l1, l2);
    }
};