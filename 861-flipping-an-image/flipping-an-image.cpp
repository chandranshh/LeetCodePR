class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
    int rows = image.size();
    int cols = image[0].size();

    vector<vector<int>> rev(rows, vector<int>(cols));
        for(int i = 0;i<image.size();i++){
            for(int j = 0;j<image[0].size();j++){
                rev[i][j] = 1 - image[i][cols - 1 - j];
            }
        }
        return rev;
    }
};