class Solution {
public:
    vector<vector<int>> dp;
    int uniquePaths(int m, int n) {
    dp.assign(m, vector<int>(n, 0));
    return dfs(0, 0, m, n);        
    }

    int dfs(int row, int col, int& m, int& n){
        if (row >= m || col >= n) { return 0; }
        if (dp[row][col] != 0) { return dp[row][col]; }
        if (row == m-1 && col == n-1) { return 1; }

        return dfs(row+1, col, m, n) + dfs(row, col+1, m, n);
        return dp[row][col];
    }
};
