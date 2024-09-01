class Solution {
public:
    bool canEat(int k, int size, int h, vector<int>& piles) {
        long totalTime = 0;
        for (int i = 0; i < size; i++) {
            totalTime += ceil((double)(piles[i]) / k);
        }
        return totalTime <= h;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = *max_element(piles.begin(), piles.end());
        int n = piles.size();
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