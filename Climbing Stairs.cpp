class Solution {
public:
    int helper(int memo[],int n){
        
        if(n<0){
            
            return 0;
        }
        else if(n==0){
            return 1;
        }
        else if(memo[n]!=-1){
            return memo[n];
        }
        
        memo[n] = helper(memo,n-1)+helper(memo,n-2);
        
        return memo[n];
    }
    int climbStairs(int n) {
        int memo[46];
        for(int i =0;i<46;i++){
            memo[i] = -1;
        }
        return helper(memo,n);
    }
};
//Tabulation approach
class Solution {
public:
    int climbStairs(int n) {
        int dp[n+1];
        dp[0] = 1;
        dp[1] = 1;
        for(int i =2;i<=n;i++){
            dp[i] = dp[i-1]+dp[i-2];
        }
        return dp[n];
        
    }
};
