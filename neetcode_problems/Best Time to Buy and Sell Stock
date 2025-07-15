class Solution {
public:
    int profit = 0;

    int maxProfit(vector<int>& prices) {
        int min = prices[0];
        int max_profit = 0;

        for (int i = 1; i < prices.size(); i++){
            if (min > prices[i]) {min = prices[i];}
            if (max_profit < prices[i] - min) {max_profit = prices[i] - min;}
        }

        return max_profit;
    }
};
