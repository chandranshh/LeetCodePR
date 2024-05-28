class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);

        dp[0] = nums[0];

        for (int i = 1; i < n; i++) {
            if (i > 1) {
                dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]);
            } else {
                dp[i] = max(dp[i - 1], nums[i]);
            }
        }

        return dp[n - 1];
    }
};