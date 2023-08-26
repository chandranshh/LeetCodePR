class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int firstPos = -1, lastPos = -1, pass=0;
        int i =0;
        while(i<n){
            if(nums[i]==target && firstPos == -1){
                firstPos= i;
                pass++;
            }
            if(nums[i]==target && pass>0){
                lastPos = i;
                pass++;
            }
            i++;
        }
        return {firstPos, lastPos};
    }
};