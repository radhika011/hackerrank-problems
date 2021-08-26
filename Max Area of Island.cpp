class Solution {
public:
    int DFS(int i,int j,vector<vector<int>>& grid,vector<vector<bool>>& visited){
        if(i>=0&&j>=0&&i<grid.size()&&j<grid[0].size()&&!visited[i][j]&&grid[i][j]==1){
            visited[i][j] = true;
            return 1+DFS(i+1,j,grid,visited)+DFS(i,j+1,grid,visited)+DFS(i-1,j,grid,visited)+DFS(i,j-1,grid,visited);
        }
        return 0;
        
        
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int h = grid.size();
        int w = grid[0].size();
        int max = 0;
        vector<vector<bool>> visited(h,vector<bool>(w,false));
        for(int i =0;i<h;i++){
            for(int j =0;j<w;j++){
                if(grid[i][j]==1&&!visited[i][j]){
                    int count = DFS(i,j,grid,visited);
                    if(count>max){
                        max = count;
                    }
                }
            }
        }
        return max;
            
    }
};
