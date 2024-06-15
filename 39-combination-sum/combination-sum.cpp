class Solution {
public:
    void findSum(int idx, int sum, vector<int>& ds, vector<vector<int>>& ans,
                 vector<int>& candidates, int target, int n) {
        if (sum == target) {
            ans.push_back(ds);
            return;
        }
        if (sum > target || idx >= n) {
            return;
        }

        for (int i = idx; i < n; i++) {
            ds.push_back(candidates[i]);
            findSum(i, sum + candidates[i], ds, ans, candidates, target, n);
            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        int n = candidates.size();
        findSum(0, 0, ds, ans, candidates, target, n);

        return ans;
    }
};