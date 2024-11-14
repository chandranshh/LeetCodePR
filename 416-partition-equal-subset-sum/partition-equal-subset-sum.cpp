class Solution {
public:
    bool partitionHelper(int idx, int target, vector<int>& nums, int n,
                         vector<vector<int>>& dp) {
        if (target == 0) {
            return true;
        }

        if (idx == n) {
            return false;
        }

        if (dp[idx][target] != -1) {
            return dp[idx][target];
        }

        bool notTaken = partitionHelper(idx + 1, target, nums, n, dp);
        bool taken = false;
        if (nums[idx] <= target) {
            taken = partitionHelper(idx + 1, target - nums[idx], nums, n, dp);
        }

        dp[idx][target] = taken || notTaken;
        return dp[idx][target];
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (sum % 2 != 0) {
            return false;
        }

        int target = sum / 2;
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
        return partitionHelper(0, target, nums, n, dp);
    }
};
