class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int mini = INT_MAX;
        int size = nums.size();

        int left = 0, right = 0;
        int sum = 0;
        while (right < size) {
            sum += nums[right];
            while (sum >= target) {
                mini = min(mini, right - left + 1);
                sum -= nums[left];
                left++;
            }
            right++;
        }
        return mini == INT_MAX ? 0 : mini;
    }
};