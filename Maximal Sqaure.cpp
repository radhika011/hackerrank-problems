
/*
Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.




*/




class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        int maxVal = 0;
        for(int i =1;i<=m;i++){
            for(int j =1;j<=n;j++){
                if(matrix[i-1][j-1]=='1'){
                    dp[i][j] = 1+min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
                    if(dp[i][j]>maxVal) maxVal = dp[i][j];
                }
                else{
                    dp[i][j] = 0;
                }
            }
        }
        return maxVal*maxVal;
        
    }
};
