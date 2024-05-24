class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int longest = 0;
        for (auto num : st) {
            if (st.find(num - 1) == st.end()) {
                int length = 1;
                while (st.find(num + 1) != st.end()) {
                    length++;
                    num++;
                }
                longest = max(longest, length);
            }
        }
        return longest;
    }
};
