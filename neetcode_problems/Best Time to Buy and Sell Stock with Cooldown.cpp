class Solution {
public:
    unordered_map<int, int> dp; //buying mode positive selling mode negative keys.
    int maxProfit(vector<int>& prices) {
        return dfs(0, 1, prices);
    }

    int dfs(int i, int buying, vector<int>& prices){ // int 1 = buying mode, -1 = selling mode.
        if (i >= prices.size()) { return 0; }
        if (dp.count(i*buying)) { return dp[i*buying]; }

        int cooldown = dfs(i+1, buying, prices);
        if(buying == 1){
            int buy = dfs(i+1, -buying, prices) - prices[i];
            return dp[i*buying] = max(buy, cooldown);
        }
        else{
            int sell = dfs(i+2, -buying, prices) + prices[i];
            return dp[i*buying] = max(sell, cooldown);
        }
    }
};
