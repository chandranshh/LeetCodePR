class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    
    int atMostK5(string &s, int k) {
        int res = 0, left = 0, n = s.size();
        unordered_map<char, int> mp;
        int right = 0;

        while (right < n) {
            if (!isVowel(s[right])) {
                left = right + 1;
                mp.clear(); 
                right++;
                continue;
            }
            mp[s[right]]++;
            // while (mp.size() > k) {
            //     mp[s[left]]--;
            //     if (mp[s[left]] == 0) {
            //         mp.erase(s[left]);
            //     }
            //     left++;
            // }
            res += right - left + 1;
            right++;
        }
        return res;
    }

    int atMostK4(string &s, int k) {
        int res = 0, left = 0, n = s.size();
        unordered_map<char, int> mp;
        int right = 0;

        while (right < n) {
            if (!isVowel(s[right])) {
                left = right + 1;
                mp.clear(); 
                right++;
                continue;
            }
            mp[s[right]]++;
            while (mp.size() > k) {
                mp[s[left]]--;
                if (mp[s[left]] == 0) {
                    mp.erase(s[left]);
                }
                left++;
            }
            res += right - left + 1;
            right++;
        }
        return res;
    }
    
    int countVowelSubstrings(string str) {
        return atMostK5(str, 5) - atMostK4(str, 4);
    }
};