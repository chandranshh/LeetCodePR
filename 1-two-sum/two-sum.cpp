class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            int moreNeeded = target - num;
            if (mpp.count(moreNeeded)!=0) {
                return {mpp[moreNeeded], i};
            }
            mpp[num] = i;
        }
        return {-1, -1};
    }
};