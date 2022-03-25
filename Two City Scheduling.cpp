
/*

A company is planning to interview 2n people. Given the array costs where costs[i] = [aCosti, bCosti], the cost of flying the ith person to city a is aCosti, and the cost of flying the ith person to city b is bCosti.

Return the minimum cost to fly every person to a city such that exactly n people arrive in each city.

knapsack basically

*/



  
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int tot = costs.size();
        this->costs = costs;
        int n = tot/2;
        vector<vector<vector<int>>> dp(tot+1,vector<vector<int>>(n+1,vector<int>(n+1,0)));
        for(int i = 1;i<=tot;i++){
            for(int j = 0;j<=n;j++){
                for(int k =0;k<=n;k++){
                    if(j==0&&k==0){
                       // dp[i][j][k] =  999999;
                        continue;
                    }
                    if(j==0){
                        dp[i][j][k] = costs[i-1][1]+dp[i-1][j][k-1];
                    }   
                    else if(k==0){
                        dp[i][j][k] = costs[i-1][0]+dp[i-1][j-1][k];
                    }
                    else{
                        int op1 = costs[i-1][1]+dp[i-1][j][k-1];
                        int op2 = costs[i-1][0]+dp[i-1][j-1][k];
                        dp[i][j][k] = min(op1,op2);
                    }
                }
            }
        }
        return dp[tot][n][n];
    }
};
