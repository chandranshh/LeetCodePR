class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int size = nums.size();
        int left = 0;
        for (int right = 0; right < size; right++) {
            if (nums[right] != val) {
                nums[left] = nums[right];
                left++;
            }
        }
        return left;
    }
};