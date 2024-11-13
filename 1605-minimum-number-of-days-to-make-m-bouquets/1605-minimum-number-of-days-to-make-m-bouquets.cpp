class Solution {
public:
    bool canBloom(vector<int>& bloomDay, int day, int m, int k) {
        int bouquets = 0;
        int flowers = 0;
        
        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= day) {
                flowers++;
                if (flowers == k) {
                    bouquets++;
                    flowers = 0;
                }
            } else {
                flowers = 0;
            }
        }
        
        return bouquets >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        long long totalFlowersNeeded = m * 1ll * k;
        int n = bloomDay.size();
        
        if (totalFlowersNeeded > n) {
            return -1;
        }
        
        int minDay = INT_MAX, maxDay = INT_MIN;
        
        for (int day : bloomDay) {
            minDay = min(minDay, day);
            maxDay = max(maxDay, day);
        }
        
        int low = minDay, high = maxDay;
        int result = high;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canBloom(bloomDay, mid, m, k)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return low;
    }
};