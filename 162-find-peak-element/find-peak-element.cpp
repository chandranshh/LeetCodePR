class Solution {
public:
    int findPeakElement(vector<int>& nums, int low, int high) {
        if (low == high) return low;
        int mid = low + (high - low) / 2;
        if (nums[mid] > nums[mid + 1]) {
            return findPeakElement(nums, low, mid);
        } else {
            return findPeakElement(nums, mid + 1, high);
        }
    }

    int findPeakElement(vector<int>& nums) {
        return findPeakElement(nums, 0, nums.size() - 1);
    }
};
