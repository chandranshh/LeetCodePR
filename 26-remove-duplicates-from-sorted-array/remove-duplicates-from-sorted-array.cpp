class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        int n = nums.size();
        int l =0, r =0;
        while(r < n){
            if(nums[l]==nums[r]){
                r++;
            }else{
                nums[l+1] = nums[r];
                l++;
            }
        }
        return l+1;
    }
};