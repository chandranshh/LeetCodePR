class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int left = 0, right = 0;
        int n = nums.size();
        int maxi = INT_MIN;
        while(right < n){   
            if(nums[left] == 1 && nums[right]==1){
                right++;
                maxi = max(maxi, right - left);
            }else if(nums[right]==0){
                left = right + 1;
                right++;
            }
        }

        return maxi == INT_MIN ? 0 : maxi ;
    }
};