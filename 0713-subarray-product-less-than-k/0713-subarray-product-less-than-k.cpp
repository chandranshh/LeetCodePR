class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1)
            return 0;

        int product = 1;
        int count = 0;
        int left = 0, right = 0;

        while (right < nums.size()) {
            product *= nums[right];

            while (product >= k) {
                product /= nums[left];
                ++left;
            }

            if (product < k) {
                count += right - left + 1;
            }
            
            right++;
        }

        return count;
    }
};