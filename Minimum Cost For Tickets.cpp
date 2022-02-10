

/*
You have planned some train traveling one year in advance. The days of the year in which you will travel are given as an integer array days. Each day is an integer from 1 to 365.

Train tickets are sold in three different ways:

a 1-day pass is sold for costs[0] dollars,
a 7-day pass is sold for costs[1] dollars, and
a 30-day pass is sold for costs[2] dollars.
The passes allow that many days of consecutive travel.

For example, if we get a 7-day pass on day 2, then we can travel for 7 days: 2, 3, 4, 5, 6, 7, and 8.
Return the minimum number of dollars you need to travel every day in the given list of days.



*/




class Solution {
public:
     vector<int> dp;
    Solution(){
        dp.resize(366,-1);
    }
    int helper(unordered_set<int>& days,vector<int>& costs,int curr){
        if(curr>365) return 0;
        if(dp[curr]!=-1) return dp[curr];
        if(days.find(curr)==days.end()) return dp[curr] = helper(days,costs,curr+1);
        int op1 = costs[0]+helper(days,costs,curr+1);
        int op2 = costs[1]+helper(days,costs,curr+7);
        int op3 = costs[2]+helper(days,costs,curr+30);
        return dp[curr]=min(op1,min(op2,op3));
        
    }
    
    
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        unordered_set<int> repo;
        for(int i = 0;i<n;i++){
            repo.insert(days[i]);
        }
       
        return helper(repo,costs,1);
    }
};
