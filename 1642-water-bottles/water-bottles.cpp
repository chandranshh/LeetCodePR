class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int total = numBottles;
        int newBot = numBottles;

        while (newBot >= numExchange) {
            total += newBot / numExchange;
            newBot = (newBot / numExchange) + (newBot % numExchange);
        }

        return total;
    }
};