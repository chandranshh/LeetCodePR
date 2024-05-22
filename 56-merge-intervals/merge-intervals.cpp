class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        int n = arr.size(); 

    sort(arr.begin(), arr.end());

    vector<vector<int>> ans;

    for (int i = 0; i < n; i++) {
        // if the current interval does not
        // lie in the last interval:
        if (ans.size() == 0 || arr[i][0] > ans[ans.size() - 1][1]) {
            ans.push_back(arr[i]);
        }
        // if the current interval
        // lies in the last interval:
        else {
            ans[ans.size() - 1][1] = max(ans[ans.size() - 1][1], arr[i][1]);
        }
    }
    return ans;
    }
};