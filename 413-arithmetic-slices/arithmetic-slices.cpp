class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if (nums.size() < 3) {
            return 0; 
        }
        
        int count = 0;
        helper(nums, nums.size() - 1, count);
        return count;
    }
    
private:
    int helper(vector<int>& nums, int end, int& count) {
        if (end < 2) {
            return 0; 
        }
        
        int sliceEndingHere = 0;
        
    
        if (nums[end] - nums[end - 1] == nums[end - 1] - nums[end - 2]) {
            sliceEndingHere = 1 + helper(nums, end - 1, count);
            count += sliceEndingHere;
        } else {
            helper(nums, end - 1, count);
        }
        
        return sliceEndingHere;
    }
};
