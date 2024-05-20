class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxP = 0;
        int buy = 0, sell = 1;

        while(sell < prices.size()){
            if(prices[buy]>prices[sell]){
                buy = sell;
            }else{
                int profit = prices[sell] - prices[buy];
                maxP = max(maxP, profit);
            }
            sell++;
        }
    return maxP;
    }
};