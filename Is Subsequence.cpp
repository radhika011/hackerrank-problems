class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.size();
        int n = t.size();
        bool dp[m+1][n+1];
        if(m==0&&n==0) return true;
        for(int i =0;i<=m;i++){
            dp[i][0] = false;
        }
        for(int j = 0;j<=n;j++){
            dp[0][j] = true;
        }
        for(int i =1;i<=m;i++){
            for(int j = 1;j<=n;j++){
                dp[i][j] = dp[i][j-1]||(dp[i-1][j-1]&&s[i-1]==t[j-1]);
            }
        }
        return dp[m][n];
    }
};
