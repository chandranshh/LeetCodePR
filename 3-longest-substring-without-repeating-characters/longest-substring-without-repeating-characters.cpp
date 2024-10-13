class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size = s.size();
        int left = 0, right = 0;
        vector<int> hash(256, 0);
        int maxLength = 0;     

        while (right < size) {
            hash[s[right]]++;
            while (hash[s[right]] > 1) {
                hash[s[left]]--;
                left++;
            }
            maxLength = max(maxLength, right - left + 1);
            right++;
        }

        return maxLength;
    }
};
