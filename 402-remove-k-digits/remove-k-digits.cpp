class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        if (k == n)
            return "0";

        stack<char> st;
        for (char digit : num) {
            while (!st.empty() && k > 0 && st.top() > digit) {
                st.pop();
                k--;
            }
            if (!st.empty() || digit != '0') {
                st.push(digit);
            }
        }

        while (!st.empty() && k--) {
            st.pop();
        }

        string result;
        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }
        reverse(result.begin(), result.end());

        return result.empty() ? "0" : result;
    }
};
