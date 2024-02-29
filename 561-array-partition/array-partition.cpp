class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int sum = 0, i = 0;
        sort(nums.begin(), nums.end());
        while(i < nums.size()){
            sum+=nums[i];
            i = i + 2;
        }
        return sum;
    }
};