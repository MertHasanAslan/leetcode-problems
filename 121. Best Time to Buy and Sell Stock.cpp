class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int max_profit = 0;
            int buy = 99999999;
            int sell = -9999999;
            for (int i = 0; i < prices.size(); i++){ 
                if (prices[i] < buy){
                    buy = prices[i];
                    sell = prices[i];
                }
                if (prices[i] > sell){
                    sell = prices[i];
                }
                if (sell-buy > max_profit){
                    max_profit = sell-buy;
                }
    
            }
            return max_profit;
        }
    };