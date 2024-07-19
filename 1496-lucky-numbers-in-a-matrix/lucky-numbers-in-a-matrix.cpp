class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int maxMin = INT_MIN;
        for (int i = 0; i < m; i++) {
            int mini = INT_MAX;
            for (int j = 0; j < n; j++)
                mini = min(mini, matrix[i][j]);
            maxMin = max(maxMin, mini);
        }

        int minMax = INT_MAX;
        for (int j = 0; j < n; j++) {
            int maxi = INT_MIN;
            for (int i = 0; i < m; i++)
                maxi = max(maxi, matrix[i][j]);
            minMax = min(minMax, maxi);
        }

        if (maxMin != minMax)
            return vector<int>{};
        return vector<int>{maxMin};
    }
};