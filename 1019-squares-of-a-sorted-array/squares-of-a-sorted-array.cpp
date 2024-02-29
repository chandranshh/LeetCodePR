class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int>sq;

        for(auto n : nums){
            sq.push_back(n*n);
        }
        sort(sq.begin(), sq.end());

        return sq;
    }
};