class Solution {
public:
    bool canBloom(vector<int>& bloomDay, int day, int m, int k) {
        int ct = 0, noBq = 0;
        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= day) {
                ct++;
            } else {
                noBq += (ct / k);
                ct = 0;
            }
        }
        noBq += (ct / k);
        return noBq >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long val = m * 1ll * k * 1ll;
        int n = bloomDay.size();
        if (val > n) {
            return -1;
        }

        int mini = INT_MAX, maxi = INT_MIN;

        for (int i = 0; i < n; i++) {
            maxi = max(maxi, bloomDay[i]);
            mini = min(mini, bloomDay[i]);
        }

        int low = mini, high = maxi;
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