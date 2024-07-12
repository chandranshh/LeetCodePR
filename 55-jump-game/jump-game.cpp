class Solution {
public:
    bool canJump(vector<int>& nums) {
        int size = nums.size();
        vector<bool> dp(size, false); 
        dp[size - 1] = true;


        for (int i = size - 2; i >= 0; --i) {
            for (int jump = 1; jump <= nums[i]; jump++) {
                if (i + jump < size && dp[i + jump]) {
                    dp[i] = true;
                    break; 
                }
            }
        }

        return dp[0];
    }
};
