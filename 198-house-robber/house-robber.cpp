class Solution {
public:
    int thief(vector<int>& nums, int idx, vector<int>& dp) {
        if (idx < 0) {
            return 0;
        }
        if (idx == 0) {
            return nums[idx];
        }
        
        if (dp[idx] != -1) {
            return dp[idx];
        }

        int pick = nums[idx] + thief(nums, idx - 2, dp);
        int notPick = 0 + thief(nums, idx - 1, dp);

        return dp[idx] = max(pick, notPick);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        int ans = thief(nums, n - 1, dp);

        return ans;
    }
};