class Solution {
public:
    int numberOfSubstrings(string s) {
        return atLeastK(s, 1);
    }

private:
    int atLeastK(string s, int k) {
        unordered_map<char, int> mp;
        int left = 0, right = 0;
        int size = s.size();
        int cnt = 0;

        while (right < size) {
            mp[s[right]]++;
            while (mp['a'] > 0 && mp['b'] > 0 && mp['c'] > 0) {
                cnt += size - right;
                mp[s[left]]--;
                left++;
            }
            right++;
        }
        return cnt;
    }
};