class Solution {
public:
    bool isUgly(int n) {

        if (n <= 0) {
            return false;
        }

        int num = n;
        while (num % 2 == 0) {
            num = num / 2;
        }
        while (num % 3 == 0) {
            num = num / 3;
        }
        while (num % 5 == 0) {
            num = num / 5;
        }

        if (num == 1)
            return true;

        return false;
    }
};