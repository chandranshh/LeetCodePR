class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.length(), m = s2.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1)); 
        return helper(s1, s2, n, m, dp);
    }

private:
    int helper(string& s1, string& s2, int i, int j, vector<vector<int>>& dp) {
        // base case if one string is empty
        if (i == 0) {
            int sum = 0;
            for (int k = 0; k < j; ++k) {
                sum += s2[k]; // sum ASCII values of remaining characters in s2
            }
            return sum;
        }
        if (j == 0) {
            int sum = 0;
            for (int k = 0; k < i; ++k) {
                sum += s1[k]; // sum ASCII values of remaining characters in s1
            }
            return sum;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }


        if (s1[i - 1] == s2[j - 1]) {
            dp[i][j] = helper(s1, s2, i - 1, j - 1, dp); // if chars are same no cost
        } else {
            // the cost of deleting characters from either string
            int delete_s1 = s1[i - 1] + helper(s1, s2, i - 1, j, dp); // curr char cost + recursion calls
            int delete_s2 = s2[j - 1] + helper(s1, s2, i, j - 1, dp); // curr char cost + recursion calls
            dp[i][j] = min(delete_s1, delete_s2); // store the min cost in dp
        }

        return dp[i][j];
    }
};