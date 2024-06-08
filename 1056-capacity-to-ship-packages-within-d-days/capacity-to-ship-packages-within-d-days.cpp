class Solution {
public:
    bool willShip(vector<int>& weights, int capacity, int days) {
        int sum = 0, dayCt = 0;
        for (int i = 0; i < weights.size(); i++) {
            sum += weights[i];
            if (sum > capacity) {
                dayCt++;
                sum = weights[i];
            }
        }
        dayCt++;
        return dayCt <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (willShip(weights, mid, days)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};
