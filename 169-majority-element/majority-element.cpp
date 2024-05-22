#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> hash;
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            hash[nums[i]]++;
        }

        for(auto& pair : hash) {
            if(pair.second > n / 2) {
                return pair.first;
            }
        }
        return -1; 
    }
};
