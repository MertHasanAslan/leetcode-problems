class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int t1 = text1.size();
        int t2 = text2.size();
        vector<vector<int>> dp(t1+1, vector<int>(t2+1, 0));

        for(int row = 1; row <= t1; row++){
            for(int col = 1; col <= t2; col++){
                if(text1[row-1] == text2[col-1]){
                    dp[row][col] = dp[row-1][col-1] + 1;
                }
                else{
                    dp[row][col] = max(dp[row-1][col], dp[row][col-1]);
                }
            }
        }

        return dp[t1][t2];
    }
};
