class Solution {
public:
    int binarySearch(const vector<int>& sorted_nums, int end, int start_idx) {
        int left = start_idx, right = sorted_nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (sorted_nums[mid] > end) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    int minOperations(vector<int>& nums) {

        unordered_set<int> unique_nums(nums.begin(), nums.end());
        vector<int> sorted_nums(unique_nums.begin(), unique_nums.end());

        sort(sorted_nums.begin(), sorted_nums.end());

        int n = nums.size();
        int m = sorted_nums.size();
        int min_operations = n;

        for (int i = 0; i < m; ++i) {
            int start = sorted_nums[i];
            int end = start + n - 1;
            int idx = binarySearch(sorted_nums, end, i);
            int count = idx - i;
            min_operations = min(min_operations, n - count);
        }

        return min_operations;
    }
};