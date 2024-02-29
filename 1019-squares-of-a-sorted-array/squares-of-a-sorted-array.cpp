class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int>sq(n);

        for(int i = 0; i<n;i++){
            sq[i]=nums[i]*nums[i];
        }
        sort(sq.begin(), sq.end());

        return sq;
    }
};