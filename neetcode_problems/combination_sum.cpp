class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<vector<int>>> dp(target +1);
        dp[0].push_back(vector<int>{}); // adding [[]] to dp[0] because we will use it for adding.

        for(int& num : nums){
            for(int t = num; t <= target; t++){ // dp[t(arget) values] since it could be some subtotal for our target value so they are mini targets
                for(auto& comb : dp[t-num]){
                    vector<int> newComb = comb;
                    newComb.push_back(num);
                    dp[t].push_back(newComb);
                }
            }
        }

        return dp[target];

    }
};
