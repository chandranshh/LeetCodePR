class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<vector<int>> dp(m, vector<int>(n, -1));
        
        int count = 0;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                count += helper(matrix, dp, i, j);
            }
        }
        
        return count;
    }
    
private:
    int helper(vector<vector<int>>& matrix, vector<vector<int>>& dp, int i, int j) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        if (i < 0 || i >= m || j < 0 || j >= n || matrix[i][j] == 0) {
            return 0;
        }
        
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        
        int top = helper(matrix, dp, i - 1, j);
        int left = helper(matrix, dp, i, j - 1);
        int topLeft = helper(matrix, dp, i - 1, j - 1);
        
        int size = min({top, left, topLeft}) + 1;
        
        dp[i][j] = size;
        
        return size;
    }
};