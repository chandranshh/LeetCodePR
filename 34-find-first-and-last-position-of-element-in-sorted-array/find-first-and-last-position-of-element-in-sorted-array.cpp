#include <vector>

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result(2, -1);

        int low = 0;
        int high = nums.size() - 1;

        while (high >= low) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                result[0] = mid;
                high = mid - 1;
            } else if (nums[mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        low = 0;
        high = nums.size() - 1;

        while (high >= low) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                result[1] = mid;
                low = mid + 1;
            } else if (nums[mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return result;
    }
};
