/*

Given a 0-indexed n x n integer matrix grid, return the number of pairs (Ri, Cj) such that row Ri and column Cj are equal.

A row and column pair is considered equal if they contain the same elements in the same order (i.e. an equal array).





*/




class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        
        vector<vector<int>> cols;
        int n = grid.size();
        for(int i =0;i<n;i++){
            vector<int> curr;
            for(int j = 0;j<n;j++){
                curr.push_back(grid[j][i]);
            }
            cols.push_back(curr);
        }
        int ans = 0;
        for(int i = 0;i<n;i++){
             vector<int> row = grid[i];
            for(int j = 0;j<n;j++){
                vector<int> col = cols[j];
                 if(row==col) ans++;
            }
           
            
            
           
        }
        return ans;
    }
};
