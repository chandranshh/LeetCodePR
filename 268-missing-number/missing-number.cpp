class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        int totalSum = (n*(n+1))/2;

        int arrSum = 0;

        for(int i =0;i<n;i++){
            arrSum+=nums[i];
        }
        return totalSum - arrSum;
    }
   
};