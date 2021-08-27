class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int dp[m][n];
        for(int i = 0;i<n;i++){
            dp[0][i] = matrix[0][i];
        }
        for(int i = 1;i<m;i++){
            for(int j = 0;j<n;j++){
                if((j+1)==n){
                     dp[i][j] = matrix[i][j] + min(dp[i-1][j],dp[i-1][j-1]);
                    continue;
                }
                else if((j-1)<0){
                    dp[i][j] = matrix[i][j] + min(dp[i-1][j+1],dp[i-1][j]);
                    continue;
                }
                dp[i][j] = matrix[i][j] + min(dp[i-1][j+1],min(dp[i-1][j],dp[i-1][j-1]));
            }
        }
        int min = INT_MAX;
        for(int i =0;i<n;i++){
            if(dp[m-1][i]<min) min = dp[m-1][i];
        }
        return min;
    }
};
