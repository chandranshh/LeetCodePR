class Solution {
public:
    int arrangeCoins(int n) {
        int num = n, count = 0, i = 1;
        
        do{
            num -= i;
            count++;
        }while(num > i++ );
        return count;
    }
};