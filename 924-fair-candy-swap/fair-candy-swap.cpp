class Solution {
public:
    vector<int> fairCandySwap(vector<int>& alice, vector<int>& bob) {
        int sumA = 0;
        for(auto &i : alice){
            sumA += i;
        }

        int sumB = 0;
        for(auto &i: bob){
            sumB += i;
        }

        int z = (sumB-sumA)/2;

    
        unordered_map<int,int>mpp;
        for(int i = 0; i<bob.size(); i++){
            mpp[bob[i]]++; 
        }

        for(int i = 0; i<alice.size(); i++){
            int x = alice[i];
            int y = x+z;
            if(mpp.find(y) != mpp.end()){
                return {x,y};
            }
        }
        
        return {};
    }
};