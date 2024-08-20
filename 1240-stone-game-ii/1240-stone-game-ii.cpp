class Solution {
public:
    int dp[100][100];

    int helper(int index, int M, const vector<int>& piles) {
        if (M * 2 >= piles.size() - index) {
            int totalStones = 0;
            for (int i = index; i < piles.size(); ++i) {
                totalStones += piles[i];
            }
            return totalStones;
        }

        if (dp[index][M] != -1) {
            return dp[index][M];
        }

        int maxStones = 0;

        for (int x = 1; x <= 2 * M; ++x) {
            if (index + x <= piles.size()) {
                int stonesTaken = 0;
                for (int i = index; i < index + x; ++i) {
                    stonesTaken += piles[i];
                }

                int remainingStones = 0;
                for (int i = index + x; i < piles.size(); ++i) {
                    remainingStones += piles[i];
                }

                maxStones = max(maxStones, stonesTaken + remainingStones - helper(index + x, max(M, x), piles));
            }
        }

        return dp[index][M] = maxStones;
    }

    int stoneGameII(vector<int>& piles) {
        memset(dp, -1, sizeof(dp));
        return helper(0, 1, piles);
    }
};