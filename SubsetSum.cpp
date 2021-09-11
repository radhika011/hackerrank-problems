bool isSubsetSum(int N, int arr[], int sum){
        // code here 
        bool dp[N+1][sum+1];
        dp[0][0] = true;
        for(int i =1;i<=N;i++){
            dp[i][0] = true;
        }
        for(int j =1;j<=sum;j++){
            dp[0][j] = false;
        }
        for(int i = 1;i<=N;i++){
            for(int j =1;j<=sum;j++){
                if(arr[i-1]<=j){
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[N][sum];
    }
