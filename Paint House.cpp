
/*
You have been given ‘N’ houses, each house can be painted with any of three colours: green, red and yellow. You are also given a “cost” matrix of ‘N’ * 3 dimension which represents the cost of painting an i-th house (0-th based indexing) with j-th colour. The colour code is as follows: green - 0, red - 1 and yellow - 2. Now, you are supposed to find the minimum cost of painting all houses such that no adjacent houses are painted with the same colour.
Codestudio Hard :)
*/





#include<limits.h>
/*
Inefficient recursive O(2^n)
int rec(vector<vector<int>> cost,int prev,int curr){
    if(curr==0) return 0;
    int i = curr-1;
    int option1 = INT_MAX;
    int option2 = INT_MAX;
    if(prev==0){
        option1 =cost[i][1]+rec(cost,1,curr-1);
        option2 =cost[i][2]+rec(cost,2,curr-1);
    }
    if(prev==1){
        option1 =cost[i][0]+rec(cost,0,curr-1);
        option2 =cost[i][2]+rec(cost,2,curr-1);
    }
    if(prev==2){
        option1 =cost[i][0]+rec(cost,0,curr-1);
        option2 =cost[i][1]+rec(cost,1,curr-1);
    }
    return min(option1,option2);
    
    
}
*/

int getMinCost(vector<vector<int>> cost){
    int n = cost.size();
    vector<vector<int>> dp(n+1,vector<int>(3,0));
    for(int i = 1;i<=n;i++){
        for(int j = 0;j<3;j++){
            int option1 = INT_MAX;
    		int option2 = INT_MAX;
            if(j==0){
                option1 =cost[i-1][1]+dp[i-1][1];
       			 option2 =cost[i-1][2]+dp[i-1][2];
            }
             if(j==1){
                option1 =cost[i-1][0]+dp[i-1][0];
       			 option2 =cost[i-1][2]+dp[i-1][2];
            }
             if(j==2){
                option1 =cost[i-1][1]+dp[i-1][1];
       			 option2 =cost[i-1][0]+dp[i-1][0];
            }
            dp[i][j] = min(option1,option2);
        }
    }
    return min(dp[n][0],min(dp[n][2],dp[n][1]));
    
}


int minCost(vector<vector<int>> &cost)
{
	//	Write your code here.
   return getMinCost(cost);
   
    
    
    
    
    
}
