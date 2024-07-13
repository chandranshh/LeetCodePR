class Solution {
public:
    bool reach_helper(vector<int>& arr, int idx, int size, vector<int>& dp) {
        if (idx >= size || idx < 0 || arr[idx] < 0) {
            return false;
        }
        if (arr[idx] == 0) {
            return true;
        }
        if (dp[idx] != -1) {
            return dp[idx];
        }
        
        int jump = arr[idx];
        arr[idx] = -1;

        bool leftJump = reach_helper(arr, idx - jump, size, dp);
        bool rightJump = reach_helper(arr, idx + jump, size, dp);

        dp[idx] = leftJump || rightJump;
        return dp[idx];
    }

    bool canReach(vector<int>& arr, int start) {
        int size = arr.size();
        vector<int> dp(size, -1);
        return reach_helper(arr, start, size, dp);
    }
};
