class Solution {
public:

    //to find nCr
    int nCr(int n, int r){
        long long res = 1;
        for(int i = 0; i < r ; i++){
            res = res * (n - i);
            res = res / (i + 1);
        }
        return (int)res;
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i = 1; i <= numRows; i++){
            vector<int>tempArr;
            for(int j = 1; j<=i; j++){
                tempArr.push_back(nCr(i - 1, j - 1));
            }
            ans.push_back(tempArr);
        }
        return ans;    
    }
};