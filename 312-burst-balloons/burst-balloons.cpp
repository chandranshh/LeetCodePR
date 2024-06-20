class Solution {
public:
    int maxHelper(int start, int end, vector<int>& nums,
                  vector<vector<int>>& dp) {
        if (start > end) {
            return 0; // no balloons left to burst
        }
        if (dp[start][end] != -1) {
            return dp[start][end];
        }
        int maxi = INT_MIN;
        for (int k = start; k <= end; k++) {
            int cost = nums[start - 1] * nums[k] * nums[end + 1];
            int leftside = maxHelper(start, k - 1, nums, dp);
            int rightside = maxHelper(k + 1, end, nums, dp);
            maxi = max(maxi, cost + leftside + rightside);
        }
        return dp[start][end] = maxi;
    }
    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return maxHelper(1, n - 2, nums, dp);
    }
};