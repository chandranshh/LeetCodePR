class Solution {
public:
    void findSum(int idx, int sum, vector<int>& ds, vector<vector<int>>& ans,
                 const vector<int>& candidates, int target) {
        if (sum == target) {
            ans.push_back(ds);
            return;
        }

        for (int i = idx; i < candidates.size(); ++i) {
            
            if (i > idx && candidates[i] == candidates[i - 1]) {
                continue;
            }

            if (sum + candidates[i] > target) {
                break;
            }

            ds.push_back(candidates[i]);
            findSum(i + 1, sum + candidates[i], ds, ans, candidates, target);
            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(candidates.begin(), candidates.end());
        findSum(0, 0, ds, ans, candidates, target);
        return ans;
    }
};
