class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = i + 1;
        while (j < n) {
            if (nums[i] == nums[j]) {
                j++;
            } else if (nums[i] != nums[j]) {
                nums[i + 1] = nums[j];
                i++;
            }
        }

        return i+1;
    }
};