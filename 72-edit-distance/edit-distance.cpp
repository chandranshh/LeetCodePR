class Solution {
public:
    int helper(string& s1, string& s2, int idx1, int idx2,
               vector<vector<int>>& dp) {
        // Base cases
        if (idx1 < 0)
            return idx2 + 1;
        if (idx2 < 0)
            return idx1 + 1;

        // If the result for this state has already been calculated, return it
        if (dp[idx1][idx2] != -1)
            return dp[idx1][idx2];

        // If the characters at the current positions match, no operation is needed
        if (s1[idx1] == s2[idx2])
            return dp[idx1][idx2] = 0 + helper(s1, s2, idx1 - 1, idx2 - 1, dp);

        // Minimum of three choices:
        // 1. Replace the character at s1[idx1] with the character at s2[idx2]
        // 2. Delete the character at s1[idx1]
        // 3. Insert the character at s2[idx2] into s1
        else
            return dp[idx1][idx2] =
                       1 + min(helper(s1, s2, idx1 - 1, idx2 - 1, dp),
                               min(helper(s1, s2, idx1 - 1, idx2, dp),
                                   helper(s1, s2, idx1, idx2 - 1, dp)));
    }

    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>>dp(m, vector<int>(n, -1));
        return helper(word1, word2, m - 1, n - 1, dp);
    }
};