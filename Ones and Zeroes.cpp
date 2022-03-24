/*
You are given an array of binary strings strs and two integers m and n.

Return the size of the largest subset of strs such that there are at most m 0's and n 1's in the subset.

A set x is a subset of a set y if all elements of x are also elements of y.




*/




class Solution {
public:
     unordered_map<string,vector<int>> umap;
    vector<string> strs;
    /*
    int rec(int curr,int i,int j){
        if(curr==0) return 0;
        string temp = strs[curr-1];
        int currZeros = umap[temp][0];
        int currOnes = umap[temp][1];
        if(currZeros<=i&&currOnes<=j){
            int op1 = 1+rec(curr-1,i-currZeros,j-currOnes);
            int op2 = rec(curr-1,i,j);
            return max(op1,op2);
        }
        return rec(curr-1,i,j);
    }
    */
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        int s = strs.size();
        this->strs = strs;
        vector<vector<vector<int>>> dp(s+1,vector<vector<int>>(m+1,vector<int>(n+1,0)));
        for(int i = 0;i<s;i++){
            int ones= 0;
            int zeros = 0;
            for(int j = 0;j<strs[i].size();j++){
                if(strs[i][j]=='1') ones++;
                else zeros++;
            }
             vector<int> curr = {zeros,ones};
            umap[strs[i]] = curr;
        }
        for(int i = 1;i<=s;i++){
            string temp = strs[i-1];
            int currZeros = umap[temp][0];
            int currOnes = umap[temp][1];
            for(int j = 0;j<=m;j++){
                for(int k = 0;k<=n;k++){
                    if(currZeros<=j&&currOnes<=k){
                        int op1 = 1+dp[i-1][j-currZeros][k-currOnes];
                        int op2 = dp[i-1][j][k];
                        dp[i][j][k] = max(op1,op2);
                        continue;
                    }
                    else{
                        dp[i][j][k] = dp[i-1][j][k];
                    }
                }
                
            }
        }
        int ans = dp[s][m][n]; 
        return ans;
    }
}; 
