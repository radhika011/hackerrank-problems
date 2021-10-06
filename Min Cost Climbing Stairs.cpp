//DP Solution
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int dp[n];
        dp[0] = cost[0];
        dp[1] = cost[1];
        for(int i =2;i<n;i++){
            dp[i] = cost[i] + min(dp[i-1],dp[i-2]);
        }
        return min(dp[n-1],dp[n-2]);
        
        
    }
};
//Recursive Solution
class Solution {
public:
    int helper(int i,vector<int> cost){
        if(i==1||i==0){
            return cost[i];
        }
        return cost[i]+min(helper(i-1,cost),helper(i-2,cost));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        return min(helper(n-2,cost),helper(n-1,cost));
    }
};
