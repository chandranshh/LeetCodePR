class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int size = temperatures.size();
        vector<int> result(size , 0);
        stack<int> temp;
        for (int day = 0; day < size; day++) {
            while (!temp.empty() &&
                   temperatures[temp.top()] < temperatures[day]) {
                result[temp.top()] = day - temp.top();
                temp.pop();
            }
            temp.push(day);
        }
        return result;
    }
};