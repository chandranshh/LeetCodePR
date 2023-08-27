class Solution {
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
        unordered_map<int, int> hm1, hm2; 
        vector<int> result;

        
        for (int num : nums1) {
            hm1[num]++;
        }

        
        for (int num : nums2) {
            if (hm1.find(num) != hm1.end() && hm1[num] > 0) {
                result.push_back(num);
                hm1[num]--;
            }
        }

        return result;
    }
};
