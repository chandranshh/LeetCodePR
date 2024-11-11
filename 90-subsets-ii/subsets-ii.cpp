class Solution {
public:
    void findSubsets(int ind, vector<int>& nums, vector<int>& ds,
                     vector<vector<int>>& ans) {
        ans.push_back(ds);
        for (int i = ind; i < nums.size(); i++) {
            ds.push_back(nums[i]);
            findSubsets(i + 1, nums, ds, ans);
            ds.pop_back();

            while (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
                i++;
            }
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(), nums.end());
        findSubsets(0, nums, ds, ans);
        return ans;
    }
};