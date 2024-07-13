class Solution {
public:
    int jump_helper(vector<int>& nums, int idx, int size, vector<int>& dp) {
        if (idx == size - 1) {
            return 0;
        }
        
        if (idx >= size - 1) {
            return INT_MAX;
        }

        if (dp[idx] != -1) {
            return dp[idx];
        }

        int mini = INT_MAX;

        for (int jump = 1; jump <= nums[idx]; jump++) {
            int dest = idx + jump;
            if (dest < size) {
                int jumps = jump_helper(nums, dest, size, dp);
                if (jumps != INT_MAX) {
                    mini = min(mini, 1 + jumps);
                }
            }
        }
        dp[idx] = mini;
        return dp[idx];
    }

    int jump(vector<int>& nums) {
        int size = nums.size();
        vector<int> dp(size, -1);
        return jump_helper(nums, 0, size, dp);
    }
};
