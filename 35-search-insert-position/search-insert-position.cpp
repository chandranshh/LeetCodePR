class Solution {
public:
    int searchInsert(vector<int>& arr, int target) {
        int size = arr.size();
        int low = 0;
        int high = size-1;

        while (high >= low) {
            int mid = low + (high - low) / 2;

            if (arr[mid] == target) {
                return mid;
            } else if (arr[mid] > target) {
                high = mid - 1;
            } else if (arr[mid] < target) {
                low = mid + 1;
            }
        }
        return low;
    }
};