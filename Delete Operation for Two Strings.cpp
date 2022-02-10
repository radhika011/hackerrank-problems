/*
Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same.

In one step, you can delete exactly one character in either string.




*/




class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i  =1;i<=m;i++){
            for(int j =1;j<=n;j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                    continue;
                }
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return m+n-(2*dp[m][n]);
    }
};
