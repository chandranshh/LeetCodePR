class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        int pos = 0, neg = 0;

        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0) {
                swap(nums[i], nums[pos]);
                pos++;
            }
        }
       
        neg = pos;
        pos = 0;

        while (pos < neg && neg < n && nums[pos] > 0) {
            swap(nums[pos + 1], nums[neg]);
            pos += 2;
            neg++;
        }

        return nums;
    }
};