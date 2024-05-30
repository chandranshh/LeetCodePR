class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false; 
        }

        vector<int> hmp(256, 0); 

        for (int i = 0; i < s.size(); i++) {
            hmp[s[i]]++;
        }

        for (int i = 0; i < t.size(); i++) {
            hmp[t[i]]--;
        }

        for (int i = 0; i < hmp.size(); i++) {
            if (hmp[i] != 0) {
                return false; 
            }
        }
        return true; 
    }
};