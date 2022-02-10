/*


Given two strings s1 and s2, return the lowest ASCII sum of deleted characters to make two strings equal.

*/





class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();
        int sum1 = 0;
        int sum2 = 0;
        for(int i = 0;i<m;i++){
            sum1+=(int)s1[i];
        }
        for(int j = 0;j<n;j++){
            sum2+=(int)s2[j];
        }
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i = 1;i<=m;i++){
            for(int j = 1;j<=n;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j] = (int)s1[i-1]+dp[i-1][j-1];
                    continue;
                }
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return sum1+sum2-(2*dp[m][n]);
        
    }
};
