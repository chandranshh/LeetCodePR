class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> m;
        vector<int> ans;
        for(auto i : nums1)
        {
            m[i]=1;
        }
        for(auto i : nums2)
        {
            if(m[i]==1)
            {
                m[i]++;
                ans.push_back(i);
            }
        }
        return ans;
    }
};