class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> ump;
        for (int i = 0; i < nums.size(); i++) {
            int find = target - nums[i];
            if (ump.find(find) != ump.end()) {
                return {i, ump[find]};
            }
            ump[nums[i]] = i;
        }
        return {-1, -1};
    }
};