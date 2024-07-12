class Solution {
public:
    bool helper(vector<int>& nums, int idx, vector<int>& dp) {
        int size = nums.size();
        
        if (idx == size - 1) {
            return true;
        }
        
        
        if (dp[idx] != -1) {
            return dp[idx];
        }
        
        
        if (nums[idx] == 0) {
            return dp[idx] = false;
        }
        
       
        for (int jump = 1; jump <= nums[idx]; ++jump) {
           
            if (idx + jump < size && helper(nums, idx + jump, dp)) {
                return dp[idx] = true; 
            }
        }
        
        return dp[idx] = false; 
    }

    bool canJump(vector<int>& nums) {
        int size = nums.size();
        vector<int> dp(size, -1); 
        
        return helper(nums, 0, dp); 
    }
};
