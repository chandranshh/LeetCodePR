class Solution {
public:
    void findSum(int idx, int cnt, int sum, vector<int>& ds,
                 vector<vector<int>>& ans, vector<int>& nums, int k, int n) {
        if (cnt == k && sum == n) {
            ans.push_back(ds);
            return;
        }
        if (cnt > k || sum > n || idx >= nums.size()) {
            return;
        }

        ds.push_back(nums[idx]);
        findSum(idx + 1, cnt + 1, sum + nums[idx], ds, ans, nums, k, n);

        ds.pop_back();
        findSum(idx + 1, cnt, sum, ds, ans, nums, k, n);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        vector<vector<int>> ans;
        vector<int> ds;
        findSum(0, 0, 0, ds, ans, nums, k, n);
        return ans;
    }
};
