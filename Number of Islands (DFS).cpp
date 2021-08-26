class Solution {
public:
    void DFS(int i,int j,vector<vector<bool>>& visited,vector<vector<char>>& grid){
        if(i>=0&&j>=0&&i<grid.size()&&j<grid[0].size()&&!visited[i][j]){
        if(grid[i][j]=='1'){
            visited[i][j] = true;
            DFS(i+1,j,visited,grid);
        DFS(i,j+1,visited,grid);
            DFS(i-1,j,visited,grid);
        DFS(i,j-1,visited,grid);
        }
        }
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int h = grid.size();
        int w = grid[0].size();
        int count = 0;
        vector<vector<bool>> visited(h,vector<bool> (w,false));
        for(int i = 0;i<h;i++){
            for(int j =0;j<w;j++){
                if(grid[i][j]=='1'&&!visited[i][j]){
                    count++;
                    DFS(i,j,visited,grid);
                }
            }
        }
        return count;
    }
};
