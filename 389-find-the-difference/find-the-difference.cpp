class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> ump;

        for (const auto& ch : s) {
            ump[ch]++;
        }

        for (const auto& ch : t) {
            if (ump.find(ch) == ump.end() || ump[ch] == 0) {
                return ch; // the character found in t but not in s
            } else {
                ump[ch]--; // decrease if the count for characters found in both
            }
        }
        
        return '\0';
    }
};