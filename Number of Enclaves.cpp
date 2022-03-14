/*
You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.

Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.




*/





class Solution {
public:
    vector<vector<bool>> visited;
    vector<vector<int>> grid;
    int m,n;
    
    int dfs(int i,int j,bool& valid){
        if(i>=m||i<0||j<0||j>=n) return 0;
        if(visited[i][j]==true) return 0;
        if(grid[i][j]==0) return 0;
        if((i+1)>=m||(i-1)<0||(j-1)<0||(j+1)>=n){
            valid = false;
        }
        visited[i][j] = 1;
        return 1+dfs(i+1,j,valid)+dfs(i-1,j,valid)+dfs(i,j+1,valid)+dfs(i,j-1,valid);
    }
    
    
    
    int numEnclaves(vector<vector<int>>& grid) {
        this->m = grid.size();
        this->n = grid[0].size();
         vector<vector<bool>> visited(m,vector<bool>(n,false));
        this->visited = visited;
        this->grid = grid;
        int ans = 0;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(this->visited[i][j]==false&&grid[i][j]==1){
                    bool valid = true;
                    int curr = dfs(i,j,valid);
                    if(valid) ans+=curr;
                }
                
            }
        }
        return ans;
        
    }
};
