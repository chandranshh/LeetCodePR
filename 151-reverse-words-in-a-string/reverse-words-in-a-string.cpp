class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        s += " ";
        string str = "";

        for (int i = 0; i < s.size(); i++) { 
            if (s[i] == ' ') {
                if (!str.empty()) { 
                    st.push(str);
                    str = "";
                }
            } else {
                str += s[i];
            }
        }

        string ans = "";
        while (!st.empty()) {
            ans += st.top() + " ";
            st.pop();
        }
        if (!ans.empty()) { 
            ans = ans.substr(0, ans.size() - 1);
        }
        return ans;
    }
};