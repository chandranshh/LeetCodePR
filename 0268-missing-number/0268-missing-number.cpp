class Solution {
private:
    bool isPresent(vector<int>& nums, int num) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == num) {
                return true;
            } else if (nums[mid] < num) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return false;
    }

public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int ans = -1;
        sort(nums.begin(), nums.end());
        for (int num = 0; num <= n; num++) {
            if (!isPresent(nums, num)) {
                ans = num;
            }
        }

        return ans;
    }
};