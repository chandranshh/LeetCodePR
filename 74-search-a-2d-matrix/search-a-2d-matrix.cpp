class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int key) {
        int ROW = matrix.size();
        int COL = matrix[0].size();
        int start = 0;
        int end = ROW * COL - 1;

        while (start <= end) {
            int mid = start + (end - start);
            int row = mid / COL;
            int col = mid % COL;
            int value = matrix[row][col];

            if (value == key)
                return 1;
            if (value > key)
                end = mid - 1;
            else
                start = mid + 1;
        }
        return 0;
    }
};