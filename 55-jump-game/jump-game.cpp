class Solution {
public:
    bool helper(vector<int>& nums, int idx, vector<int>& dp) {
        if (idx >= nums.size() - 1) {
            return true;
        }

        if (nums[idx] == 0) {
            return false;
        }

        if (dp[idx] != -1) {
            return dp[idx];
        }

        for (int jump = 1; jump <= nums[idx]; jump++) {
            if (helper(nums, idx + jump, dp)) {
                return dp[idx] = true;
            }
        }

        return dp[idx] = false;
    }

    bool canJump(vector<int>& nums) {
        int size = nums.size();
        vector<int> dp(size+1, -1);

        return helper(nums, 0, dp);
    }
};

// giving tle
//  class Solution {
//  public:
//      bool helper(vector<int>& nums, int size, int idx, vector<bool>& dp) {
//          if (idx >= size) {
//              return false;
//          }

//         if (idx == size - 1) {
//             return true;
//         }

//         if (dp[idx] != false) {
//             return dp[idx];
//         }

//         for (int i = 1; i <= nums[idx]; i++) {
//             if (helper(nums, size, idx + i, dp)) {
//                 dp[idx] = true;
//             }
//         }

//         return dp[idx];
//     }

//     bool canJump(vector<int>& nums) {
//         int size = nums.size();
//         vector<bool> dp(size + 1, false);

//         return helper(nums, size, 0, dp);
//     }
// };