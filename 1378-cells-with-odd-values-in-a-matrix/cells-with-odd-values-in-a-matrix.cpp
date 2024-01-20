class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        vector<vector<int>> matrix(m, vector<int>(n,0));

        int rows = indices.size();
        int col = indices[0].size();

        for(int a = 0; a<rows; a++){
                int r = indices[a][0];//0
                int c = indices[a][1];//1

                for(int i =0;i<n;i++){
                    matrix[r][i]++;
                }
                for(int j=0;j<m;j++){
                    matrix[j][c]++;
                }              

            }
            int odd = 0;
        for(int i =0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]%2!=0){
                    odd++;
                }
            }
        }  
         return odd;
        }
         

       

};