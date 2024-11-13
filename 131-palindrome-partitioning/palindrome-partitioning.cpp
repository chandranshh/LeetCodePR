class Solution {
public:
    bool checkPalindrome(string &s) {
        int n = s.size();
        if (n == 1) {
            return true;
        }
        int left = 0, right = n - 1;
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }

    vector<vector<string>> helper(int idx, int end, string& s, unordered_map<int, vector<vector<string>>>& dp) {
        if (idx >= end) {
            return {{}};
        }

        if (dp.find(idx) != dp.end()) {
            return dp[idx];
        }

        vector<vector<string>> result;
        for (int i = idx; i < end; i++) {
            string substring = s.substr(idx, i - idx + 1);
            if (checkPalindrome(substring)) {
                vector<vector<string>> nextPartitions = helper(i + 1, end, s, dp);
                for (vector<string>& partition : nextPartitions) {
                    partition.insert(partition.begin(), substring);
                    result.push_back(partition);
                }
            }
        }

        dp[idx] = result;
        return result;
    }

    vector<vector<string>> partition(string s) {
        unordered_map<int, vector<vector<string>>> dp;
        return helper(0, s.size(), s, dp);
    }
};