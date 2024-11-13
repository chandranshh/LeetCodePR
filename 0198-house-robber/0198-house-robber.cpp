class Solution {
public:
    int thief(vector<int>& nums, int idx, vector<int>& dp) {
        if (idx >= nums.size()) {
            return 0;
        }
        
        if (dp[idx] != -1) {
            return dp[idx];
        }

        int pick = nums[idx] + thief(nums, idx + 2, dp);
        int notPick = thief(nums, idx + 1, dp);

        return dp[idx] = max(pick, notPick);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        int ans = thief(nums, 0, dp);

        return ans;
    }
};