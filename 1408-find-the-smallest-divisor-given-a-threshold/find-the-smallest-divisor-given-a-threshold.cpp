class Solution {
public:
    bool isDivisor(vector<int>& nums, int divisor, int threshold) {
        int divSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            divSum += ceil((double)nums[i] / (double)divisor);
        }
        return divSum <= threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();

        if (n > threshold) {
            return -1;
        }

        int maxi = *max_element(nums.begin(), nums.end());

        int low = 1, high = maxi;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isDivisor(nums, mid, threshold)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};