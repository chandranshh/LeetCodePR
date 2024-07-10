class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string> s;
        for (const auto& log : logs) {
            if (log == "../") {
                if (!s.empty()) {
                    s.pop();
                }
            } else if (log == "./") {
                continue;
            } else {
                s.push(log);
            }
        }
        return s.size();
    }
};