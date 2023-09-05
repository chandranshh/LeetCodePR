class Solution {
public:
    int arrangeCoins(int n) {
    long left = 1;
    long right = n;
    long result = 0; 

    while (left <= right) {
        long mid = left + (right - left) / 2;
        long totalCoins = (mid * (mid + 1)) / 2;  
        if (totalCoins == n) {
            return mid;
        } else if (totalCoins < n) {
            left = mid + 1;
            result = mid; 
        } else {
            right = mid - 1;
        }
    }

    return result;
}

};