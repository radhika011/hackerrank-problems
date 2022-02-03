/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete at most two transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).





*/




//Inefficient - O(2^n)
class Solution {
public:
    
    int helper(vector<int>& prices,bool bought,int rem,int curr,int bprice){
        int n = prices.size();
        if(rem==0) return 0;
        if(curr==n) return 0;
        if(bought){
            if(prices[curr]<=bprice) return helper(prices,bought,rem,curr+1,bprice);
            else{
                return max( helper(prices,bought,rem,curr+1,bprice),prices[curr]-bprice+helper(prices,false,--rem,curr+1,-1));
            }
        }
        return max(helper(prices,bought,rem,curr+1,-1),helper(prices,true,rem,curr+1,prices[curr]));
    }
    
    
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        return helper(prices,false,2,0,-1);
    }
};
//Efficient - O(n)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int leftmin = prices[0];
        vector<int> left(n,0);
        for(int i =1;i<n;i++){
            
            left[i] = max(left[i-1],prices[i]-leftmin);
            leftmin = min(leftmin,prices[i]);
        }
        int rightmax = prices[n-1];
        vector<int> right(n,0);
        for(int i = n-2;i>=0;i--){
            right[i] = max(right[i+1],rightmax-prices[i]);
            rightmax = max(prices[i],rightmax);
        }
        int ans = 0;
        for(int i = 0;i<n;i++){
            ans = max(ans,left[i]+right[i]);
        }
        return ans;
    }
};

