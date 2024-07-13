class Solution {
public:
    string rle(const string& str) {
        string result;
        int count = 1;

        for (int i = 0; i < str.length(); ++i) {
            if (i + 1 < str.length() && str[i] == str[i + 1]) {
                count++;
            } else {
                result += to_string(count) + str[i];
                count = 1;
            }
        }

        return result;
    }

    string countAndSay(int n) {
        string result = "1";

        for (int i = 1; i < n; ++i) {
            result = rle(result);
        }

        return result;
    }
};
