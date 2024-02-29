class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int maxProduct = nums[n - 1] * nums[n - 2] * nums[n - 3];
        int minProduct = nums[0] * nums[1] * nums[n - 1];

        return max(maxProduct, minProduct);
    }
};
