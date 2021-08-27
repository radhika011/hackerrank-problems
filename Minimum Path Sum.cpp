class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int dp[m][n];
        dp[0][0] = grid[0][0];
        int sumUptoNow = dp[0][0];
        for(int i = 1;i<m;i++){
            dp[i][0] = sumUptoNow+grid[i][0];
            sumUptoNow += grid[i][0];
        }
        sumUptoNow = dp[0][0];
        for(int i =1;i<n;i++){
            dp[0][i] = sumUptoNow+grid[0][i];
            sumUptoNow += grid[0][i];
        }
        for(int i =1;i<m;i++){
            for(int j =1;j<n;j++){
                dp[i][j] = grid[i][j]+min(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[m-1][n-1];
    }
};
