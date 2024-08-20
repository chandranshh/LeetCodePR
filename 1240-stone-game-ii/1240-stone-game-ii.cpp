class Solution {
public:
    int solveForAlice(vector<int>& piles, vector<vector<vector<int>>>& dp, int person, int i, int M, int n) {
        if (i >= n)
            return 0;
        
        if (dp[person][i][M] != -1)
            return dp[person][i][M];
        
        int result = (person == 1) ? -1 : INT_MAX;
        int stones = 0;
        
        for (int x = 1; x <= min(2 * M, n - i); x++) {
            stones += piles[i + x - 1];
            
            if (person == 1) { // Alice
                result = max(result, stones + solveForAlice(piles, dp, 0, i + x, max(M, x), n));
            } else { // Bob
                result = min(result, solveForAlice(piles, dp, 1, i + x, max(M, x), n));
            }
        }
        
        return dp[person][i][M] = result;
    }
    
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<vector<int>>> dp(2, vector<vector<int>>(n + 1, vector<int>(n + 1, -1)));
        
        return solveForAlice(piles, dp, 1, 0, 1, n);
    }
};