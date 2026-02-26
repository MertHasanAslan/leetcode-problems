class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) { return 0; }
        if (nums.size() == 1) { return nums[0]; }

        vector<int> dp(nums.size(), 0);

        dp[0] = nums[0];
        dp[1] = max(nums[1], nums[0]);
        for (int i = 2; i < nums.size(); i++){
            int skip = dp[i-1];
            int take = nums[i] + dp[i-2];

            dp[i] = max(take, skip);
        }

        return dp[nums.size()-1];
    }
};