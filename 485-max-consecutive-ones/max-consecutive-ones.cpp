class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int maxLen = 0;
        int currLen = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                currLen++;
            } else {
                maxLen = max(maxLen, currLen);
                currLen = 0;
            }
        }

        return max(maxLen, currLen);
    }
};