class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int low = 0, high = n - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int maxRow = 0;

            for (int i = 0; i < m; ++i) {
                if (mat[i][mid] > mat[maxRow][mid]) {
                    maxRow = i;
                }
            }

            bool isLeftBig = false;
            bool isRightBig = false;

            if (mid > 0 && mat[maxRow][mid - 1] > mat[maxRow][mid]) {
                isLeftBig = true;
            }

            if (mid < n - 1 && mat[maxRow][mid + 1] > mat[maxRow][mid]) {
                isRightBig = true;
            }

            if (!isLeftBig && !isRightBig) {
                return {maxRow, mid};
            } else {
                if (isRightBig) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }

        return {-1, -1};
    }
};