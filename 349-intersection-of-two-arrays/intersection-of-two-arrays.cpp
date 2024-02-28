class Solution {
public:
    vector<int> intersection(vector<int>& nums1, std::vector<int>& nums2) {
        unordered_set<int> set(nums1.begin(), nums1.end());
        vector<int> result;

        for (int num : nums2) {
            if (set.find(num) != set.end()) {
                result.push_back(num);
                set.erase(num);
            }
        }

        return result;
    }
};
