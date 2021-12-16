/*
You are given an m x n integer array grid where grid[i][j] could be:

1 representing the starting square. There is exactly one starting square.
2 representing the ending square. There is exactly one ending square.
0 representing empty squares we can walk over.
-1 representing obstacles that we cannot walk over.
Return the number of 4-directional walks from the starting square to the ending square, that walk over every non-obstacle square exactly once.

First HARD problem solved :)




*/






class Solution {
public:
    
    bool checkDone(vector<vector<bool>> visited,vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        for(int i =0;i<m;i++){
            for(int j =0;j<n;j++){
                if(!visited[i][j]&&grid[i][j]==0) return false;
                
                
            }
        }
        return true;
        
        
    }
    
    
    
    void dfs(int i,int j,int m,int n,vector<vector<bool>> visited,int &count,vector<vector<int>>& grid){
        if(i<0||j<0||i>=m||j>=n) return;
        if(visited[i][j]) return;
        visited[i][j] = true;
        if(grid[i][j]==2){
            if(!checkDone(visited,grid)) return;
            count+=1;
            return;
        }
        if(grid[i][j]==-1) return;
        dfs(i+1,j,m,n,visited,count,grid);
        dfs(i-1,j,m,n,visited,count,grid);
        dfs(i,j+1,m,n,visited,count,grid);
         dfs(i,j-1,m,n,visited,count,grid);
        
        
    }
    
    
    
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        for(int i =0;i<m;i++){
            for(int j =0;j<n;j++){
                if(grid[i][j]==1){
                    
                    dfs(i,j,m,n,visited,count,grid);
                    break;
                    
                    
                }
                
            }
        }
        return count;
        
        
        
        
        
        
    }
};
