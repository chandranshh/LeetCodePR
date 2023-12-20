class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int max = 0;
        
        int sizeOuter =  accounts.size();
        int sizeInner =  accounts[0].size();

        for(int i = 0;  i<sizeOuter;i++){
            int sum =0;
            for(int j = 0; j<sizeInner;j++){
                sum+=accounts[i][j];
            }
            if(max<=sum){
                max = sum;
            }
            sum=0;
        }
        return max;
    }
};