class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        partitionHelper(0, s, path, res);
        return res;
    }

    void partitionHelper(int index, string s, vector<string>& path,
                         vector<vector<string>>& res) {
        if (index == s.size()) {
            res.push_back(path);
            return;
        }

        string currentSubstring = "";
        for (int i = index; i < s.size(); ++i) {
            currentSubstring += s[i];
            if (isPalindrome(s, index, i)) {
                path.push_back(currentSubstring);
                partitionHelper(i + 1, s, path, res);
                path.pop_back();
            }
        }
    }

    bool isPalindrome(string s, int start, int end) {
        while (start <= end) {
            if (s[start++] != s[end--])
                return false;
        }
        return true;
    }
};