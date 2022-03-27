/*

There are n piles of coins on a table. Each pile consists of a positive number of coins of assorted denominations.

In one move, you can choose any coin on top of any pile, remove it, and add it to your wallet.

Given a list piles, where piles[i] is a list of integers denoting the composition of the ith pile from top to bottom, and a positive integer k, return the maximum total value of coins you can have in your wallet if you choose exactly k coins optimally.



*/





class Solution {
public:
    
    vector<vector<int>> piles;
    vector<vector<int>> memo;
    int rec(int i,int rem){
        if(i==0) return 0;
        if(rem==0) return 0;
        if(memo[i][rem]!=-1) return memo[i][rem];
        int currSum = 0;
        //cout<<i<<" "<<rem<<endl;
        int ans = INT_MIN;
        ans = max(ans,rec(i-1,rem));
        for(int j = 0;j<rem&&j<piles[i-1].size();j++){
            currSum+=piles[i-1][j];
            int op1 = currSum+rec(i-1,rem-(j+1));
            ans = max(ans,op1);
            
        }
        //cout<<ans<<endl;
        return memo[i][rem] = ans;
    }
    
    
    
    
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        this->piles = piles;
        int n = piles.size();
        vector<vector<int>> memo(n+1,vector<int>(k+1,-1));
        this->memo = memo;
        return rec(n,k);
    }
};
