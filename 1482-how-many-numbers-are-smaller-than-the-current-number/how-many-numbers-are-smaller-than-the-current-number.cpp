class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> v;
        int count = 0;
        for(int i = 0; i<nums.size();i++){
            for(auto n : nums){
                if(nums[i]>n){
                    count++;
                }
            }
            v.push_back(count);
            count = 0;
        }
        return v;
    }
};