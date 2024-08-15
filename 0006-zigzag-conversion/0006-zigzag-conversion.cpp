class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s; 

        vector<vector<char>> ans(numRows, vector<char>(s.size(), '*'));
        int i = 0, j = 0;
        int st = 0;
        int dir = 0; // 0 for down, 1 for diagonal up

        while (st < s.size()) {
            if (dir == 0) { // go down
                ans[i++][j] = s[st++];
                if (i == numRows) {
                    i -= 2; // up by two rows
                    j++;    // right by one column
                    dir = 1;
                }
            } else if (dir == 1) { // go diagonal up
                ans[i--][j++] = s[st++];
                if (i < 0) {
                    i += 2; // down by two rows
                    j--;    // left by one column
                    dir = 0;
                }
            }
        }

        string ns = "";
        for (int i = 0; i < ans.size(); i++) {
            for (int j = 0; j < ans[0].size(); j++) {
                if (ans[i][j] != '*') {
                    ns.push_back(ans[i][j]);
                }
            }
        }
        return ns;
    }
};