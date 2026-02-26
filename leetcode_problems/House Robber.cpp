class Solution {
public:
    vector<int> dp;
    int rob(vector<int>& nums) {
        dp.assign(nums.size(), -1);

        return robHelper(nums, 0);
    }

    int robHelper(vector<int>& nums, int index){
        if (index >= nums.size()) { return 0; }

        if (dp[index] != -1) { return dp[index]; }

        int skip = robHelper(nums, index+1);
        int take = nums[index] + robHelper(nums, index+2);

        dp[index] = max(skip , take);
        return dp[index];
    }
};