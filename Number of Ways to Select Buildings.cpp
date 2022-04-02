/*
You are given a 0-indexed binary string s which represents the types of buildings along a street where:

s[i] = '0' denotes that the ith building is an office and
s[i] = '1' denotes that the ith building is a restaurant.
As a city official, you would like to select 3 buildings for random inspection. However, to ensure variety, no two consecutive buildings out of the selected buildings can be of the same type.

For example, given s = "001101", we cannot select the 1st, 3rd, and 5th buildings as that would form "011" which is not allowed due to having two consecutive buildings of the same type.
Return the number of valid ways to select 3 buildings.

WHY TF IS A VECTOR GIVING TLE BUT AN ARRAY ISN'T?


*/


typedef long long ll; 
class Solution { 
    public: 
    ll rec(string s,string t){ 
        int n = s.size(); 
        long long dp[n+1][4];
        for(int i = 0;i<=n;i++){ 
            for(int j = 0;j<=3;j++){
                if(j==0){
                    dp[i][j] = 1;
                    continue;
                }
                if(i==0){
                    dp[i][j] = 0;
                    continue;
                }
                if(s[i-1]==t[j-1]){ 
                    dp[i][j] = dp[i-1][j-1]+dp[i-1][j]; } 
                else{ dp[i][j] = dp[i-1][j]; } } } 
        return dp[n][3]; } 
    long long numberOfWays(string s) { 
        return rec(s,"101")+rec(s,"010"); 
    } 
};
