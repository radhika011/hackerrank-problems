//Recursive Approach
class Solution {
public:
    int INF = 100000;
    int helper(int remSum,int curr,vector<int> sq){
        //cout<<remSum<<" "<<sq[curr-1]<<endl;
        if(remSum==0) return 0;
        if(curr==0) return INF;
    
        if(sq[curr-1]<=remSum){
            int rem = remSum/sq[curr-1];
            //cout<<sq[curr-1]<<" "<<rem<<endl;
            return min((rem+helper(remSum-(rem*sq[curr-1]),curr-1,sq)),helper(remSum,curr-1,sq));
        }
        else{
            return helper(remSum,curr-1,sq);
        }
    }
    int numSquares(int n) {
        if(n==1) return 1;
        vector<int> sq;
        for(int i =1;(i*i)<=n;i++){
            sq.push_back((i*i));
        }
        int len = sq.size();
        return helper(n,len,sq);
    }
};
//DP Approach
class Solution {
public:
    
    int numSquares(int n) {
        if(n==1) return 1;
        int INF = 100000;
        vector<int> sq;
        for(int i =1;(i*i)<=n;i++){
            sq.push_back((i*i));
        }
        int len = sq.size();
        vector<vector<int>> dp(len+1,vector<int>(n+1));
        for(int i =0;i<=len;i++){
            dp[i][0] = 0;
        }
        for(int i = 1;i<=n;i++){
            dp[0][i] = INF;
        }
        for(int i =1;i<=len;i++){
            for(int j =1;j<=n;j++){
                if(sq[i-1]<=j){
                    int rem = j/sq[i-1];
                    int diff = rem*sq[i-1];
                    dp[i][j] = min(rem+dp[i-1][j-diff],dp[i-1][j]);
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[len][n];
        
        
    }
};
