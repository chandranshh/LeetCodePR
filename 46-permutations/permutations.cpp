class Solution {
public:
    void generatePermute(vector<int>& nums, int start, int end,
                         vector<vector<int>>& result) {
        if (start == end) {
            result.push_back(nums);
        } else {
            for (int i = start; i <= end; i++) {
                swap(nums[start], nums[i]);
                generatePermute(nums, start + 1, end, result);
                swap(nums[start], nums[i]);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int N = nums.size();
        vector<vector<int>> result;
        generatePermute(nums, 0, N - 1, result);
        return result;
    }
};