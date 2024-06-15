class Solution {
public:
    void findSum(int idx, int sum, vector<int>& ds, vector<vector<int>>& ans,
                 vector<int>& candidates, int target) {
        if (sum == target) {
            ans.push_back(ds);
            return;
        }
        if (sum > target || idx >= candidates.size()) {
            return;
        }

        ds.push_back(candidates[idx]);
        findSum(idx + 1, sum + candidates[idx], ds, ans, candidates, target);
        ds.pop_back();

        while (idx + 1 < candidates.size() &&
               candidates[idx] == candidates[idx + 1]) {
            idx++;
        }
        findSum(idx + 1, sum, ds, ans, candidates, target);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(candidates.begin(), candidates.end());
        findSum(0, 0, ds, ans, candidates, target);
        return ans;
    }
};
