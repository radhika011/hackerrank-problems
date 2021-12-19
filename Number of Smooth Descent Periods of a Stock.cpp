
/*
You are given an integer array prices representing the daily price history of a stock, where prices[i] is the stock price on the ith day.

A smooth descent period of a stock consists of one or more contiguous days such that the price on each day is lower than the price on the preceding day by exactly 1. The first day of the period is exempted from this rule.

Return the number of smooth descent periods.

1D DP



*/



typedef long long ll;
class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        ll ans = 1;
        int n = prices.size();
        vector<ll> dp(n,1);
        for(int i =1;i<n;i++){
            if(prices[i-1]-prices[i]==1){
                dp[i]+=dp[i-1];
            }
            ans+=dp[i];
        }
       
        
        
        
        
        return ans;
    }
};
