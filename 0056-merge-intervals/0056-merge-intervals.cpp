class Solution
{
	public:
		vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if (intervals.empty()) {
        return {};
    }

    vector<vector<int>> result;
    sort(intervals.begin(), intervals.end());

    int start = intervals[0][0]; //1 1 8
    int end = intervals[0][1]; //3 6 10

    for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i][0] <= end) {
            end = max(end, intervals[i][1]);
        } else {
            result.push_back({start, end});
            start = intervals[i][0];
            end = intervals[i][1];
        }
    }

    result.push_back({start, end});
    return result;
}
};
