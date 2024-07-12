class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int size = nums.size();
        if (size < 3) {
            return 0;
        }

        int diff = nums[1] - nums[0];
        int si = 1;
        int count = 0;

        for (int i = 2; i < size; i++) {
            int curr_diff = nums[i] - nums[i - 1];
            if (curr_diff == diff) {
                si++;
            } else {
                diff = curr_diff;
                si = 1;
            }

            if (si >= 2) {
                count += si - 1;
            }
        }

        return count;
    }
};