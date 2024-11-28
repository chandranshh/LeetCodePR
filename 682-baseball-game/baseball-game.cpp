class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> s;
        int size = operations.size();
        
        for (int i = 0; i < size; i++) {
            if (operations[i] == "C") {
                if (!s.empty()) {
                    s.pop();
                }
            } else if (operations[i] == "D") {
                if (!s.empty()) {
                    s.push(2 * s.top());
                }
            } else if (operations[i] == "+") {
                if (s.size() >= 2) {
                    int top1 = s.top();
                    s.pop();
                    int top2 = s.top();
                    s.push(top1);
                    s.push(top1 + top2);
                }
            } else {
                int score;
                stringstream ss(operations[i]);
                ss >> score;
                s.push(score);
            }
        }
        int totalScore = 0;
        while (!s.empty()) {
            totalScore += s.top();
            s.pop();
        }
        
        return totalScore;
    }
};