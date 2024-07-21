class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }

private:
    int atMostK(vector<int>& nums, int k) {
        int size = nums.size();
        int left = 0, right = 0;
        int cnt = 0, currOdd = 0;
        while (right < size) {

            if (nums[right] % 2 != 0) {
                currOdd++;
            }

            while (currOdd > k) {
                if (nums[left] % 2 != 0) {
                    currOdd--;
                }
                left++;
            }

            cnt += (right - left + 1);
            right++;
        }
        return cnt;
    }
};