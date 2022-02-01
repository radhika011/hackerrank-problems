


/*

You are given an m x n integer matrix points (0-indexed). Starting with 0 points, you want to maximize the number of points you can get from the matrix.

To gain points, you must pick one cell in each row. Picking the cell at coordinates (r, c) will add points[r][c] to your score.

However, you will lose points if you pick a cell too far from the cell that you picked in the previous row. For every two adjacent rows r and r + 1 (where 0 <= r < m - 1), picking cells at coordinates (r, c1) and (r + 1, c2) will subtract abs(c1 - c2) from your score.

Return the maximum number of points you can achieve.

abs(x) is defined as:

x for x >= 0.
-x for x < 0.

This bitchy ass problem is related to Sightseeing Pairs and Min Falling Path Sum


*/

typedef long long ll;
class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size();
        int n = points[0].size();
        vector<vector<ll>> dp(m,vector<ll>(n,0));
        for(int i = 0;i<n;i++){
            dp[0][i] = points[0][i];
        }
        for(int i =1;i<m;i++){
           vector<ll> left_dp(n,0);
            vector<ll> right_dp(n,0);
            left_dp[0] = dp[i-1][0];
            for(int j =1;j<n;j++){
                left_dp[j] = max(dp[i-1][j]+j,left_dp[j-1]);
            }
            right_dp[n-1] = dp[i-1][n-1]-n+1;
            for(int j = n-2;j>=0;j--){
                right_dp[j]= max(dp[i-1][j]-j,right_dp[j+1]);
            }
            for(int j =0;j<n;j++){
                dp[i][j] = max(left_dp[j]-j,right_dp[j]+j)+points[i][j];
            }
        }
        ll ans = 0;
        for(int i = 0;i<n;i++){
            ans = max(ans,dp[m-1][i]);
        }
        return ans;
    }
};
