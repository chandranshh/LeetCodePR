class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& nums, int partitionSize) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return maxSumHelper(0, nums, partitionSize, dp);
    }

    int maxSumHelper(int startIndex, vector<int>& nums, int partitionSize,
                     vector<int>& dp) {
        int n = nums.size();

        if (startIndex == n)
            return 0;

        if (dp[startIndex] != -1)
            return dp[startIndex];

        int partitionLength = 0;
        int maxElementInPartition = INT_MIN;
        int maxSumForCurrentPartition = INT_MIN;

        for (int endIndex = startIndex;
             endIndex < min(startIndex + partitionSize, n); endIndex++) {
            partitionLength++;
            maxElementInPartition = max(maxElementInPartition, nums[endIndex]);
            int sum = partitionLength * maxElementInPartition +
                      maxSumHelper(endIndex + 1, nums, partitionSize, dp);
            maxSumForCurrentPartition = max(maxSumForCurrentPartition, sum);
        }

        return dp[startIndex] = maxSumForCurrentPartition;
    }
};