class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
        return false;
    }

    long long n = x, r = 0;

    while (n > 0) {
        r = r * 10 + (n % 10);
        n = n / 10;
    }
    return r == x;

    }
};