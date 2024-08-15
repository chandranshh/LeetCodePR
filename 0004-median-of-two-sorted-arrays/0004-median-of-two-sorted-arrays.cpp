class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int p1 = 0, p2 = 0;
        int s1 = nums1.size(), s2 = nums2.size();

        vector<int> merged;

        while (p1 < s1 && p2 < s2) {
            if (nums1[p1] <= nums2[p2]) {
                merged.push_back(nums1[p1]);
                p1++;
            } else {
                merged.push_back(nums2[p2]);
                p2++;
            }
        }

        while (p1 < s1) {
            merged.push_back(nums1[p1]);
            p1++;
        }
        while (p2 < s2) {
            merged.push_back(nums2[p2]);
            p2++;
        }

        int merged_size = merged.size();
        if (merged_size % 2 == 0) {
            return (merged[merged_size / 2 - 1] + merged[merged_size / 2]) /
                   2.0;
        } else {
            return merged[merged_size / 2];
        }
    }
};