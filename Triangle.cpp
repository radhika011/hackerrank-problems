/*

Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.



*/


//Space = O(n*t) where n = number of rows, t= number of cols in the last row


class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp;
        vector<int> curr;
        curr.push_back(triangle[0][0]);
        dp.push_back(curr);
        for(int i =1;i<n;i++){
            vector<int> curr;
            curr.push_back(dp[i-1][0]+triangle[i][0]);
             
            for(int j =1;j<triangle[i].size()-1;j++){
                //cout<<"now"<<i<<" "<<j<<endl;
                int op1 = dp[i-1][j];
                int op2 = dp[i-1][j-1];
                curr.push_back(min(op1,op2)+triangle[i][j]);
            }
            curr.push_back(dp[i-1][triangle[i-1].size()-1]+triangle[i][triangle[i].size()-1]);
            dp.push_back(curr);
        }
        int ans = INT_MAX;
        for(int i = 0;i<triangle[n-1].size();i++){
            ans = min(ans,dp[n-1][i]);
        }
        return ans;
    }
};
//Space = O(n)


