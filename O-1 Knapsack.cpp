int Solution::solve(vector<int> &A, vector<int> &B, int C) {
    int n = A.size();
    int sum = C;
    int dp[n+1][sum+1];
    for(int i = 0;i<=n;i++){
        dp[i][0] = 0;
    }
    for(int i = 0;i<=sum;i++){
        dp[0][i] = 0;
    }
    for(int i =1;i<=n;i++){
        for(int j =1;j<=sum;j++){
            if(B[i-1]<=j){
                dp[i][j] = max(dp[i-1][j],A[i-1]+dp[i-1][j-B[i-1]]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][sum];

}
