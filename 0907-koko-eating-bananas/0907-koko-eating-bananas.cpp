class Solution {
private:
    bool canEat(int k, int size, int h, vector<int>& piles) {
        long long totalTime = 0;
        for (int i = 0; i < size; i++) {
            totalTime += ceil((double)(piles[i]) / k);
        }
        return totalTime <= h;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = INT_MIN;
        int n = piles.size();
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, piles[i]);
        }
        int start = 1, end = maxi;
        int result = maxi;

        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (canEat(mid, n, h, piles)) {
                result = mid; 
                end = mid - 1; 
            } else {
                start = mid + 1;
            }
        }

        return result;
    }
};