class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ugly(n + 1);
        int p2, p3, p5;
        ugly[1] = 1;
        p2 = p3 = p5 = 1;

        for (int i = 2; i <= n; i++) {
            int ugly2 = ugly[p2] * 2;
            int ugly3 = ugly[p3] * 3;
            int ugly5 = ugly[p5] * 5;

            ugly[i] = min(ugly2, min(ugly3, ugly5));

            if (ugly[i] == ugly2) {
                p2++;
            }
            if (ugly[i] == ugly3) {
                p3++;
            }
            if (ugly[i] == ugly5) {
                p5++;
            }
        }
        return ugly[n];
    }
};