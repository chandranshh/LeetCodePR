class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int left = 0, right = 0;
        int maxCount =
            0; // count of the most frequent character in the current window
        int longest = 0;

        vector<int> count(26, 0); // count of characters in the current window

        while (right < n) {
            // increment the count of the current character
            count[s[right] - 'A']++;
            maxCount =
                max(maxCount, count[s[right] - 'A']); // update the maxCount

            // calculate the number of characters to change
            int changes = (right - left + 1) - maxCount;

            // if changes exceed k, shrink the window from the left
            if (changes > k) {
                count[s[left] -
                      'A']--; // decrease the count of the left character
                left++;       // move the left pointer to the right
            }

            // update the longest length of the substring found
            longest = max(longest, right - left + 1);
            right++; // move the right pointer to the right
        }

        return longest;
    }
};