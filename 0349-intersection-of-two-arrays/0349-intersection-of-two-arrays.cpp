class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2)    {

        vector<int> result;

set<int> s1(nums1.begin(), nums1.end());
set<int> s2(nums2.begin(), nums2.end());

for (auto num : s1) {
    if (s2.find(num)!=s2.end()) {
        result.emplace_back(num);
    }
}

return result;
    }
};