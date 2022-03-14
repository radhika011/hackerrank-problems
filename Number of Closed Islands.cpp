/*

Given a 2D grid consists of 0s (land) and 1s (water).  An island is a maximal 4-directionally connected group of 0s and a closed island is an island totally (all left, top, right, bottom) surrounded by 1s.

Return the number of closed islands.





*/




class Solution {
public:
    vector<vector<bool>> visited;
    vector<vector<int>> grid;
    int m,n;
    int dfs(int i,int j,bool& valid){
        if(i>=m||i<0||j<0||j>=n) return 0;
        if(visited[i][j]==true) return 0;
        if(grid[i][j]==1) return 0;
        if((i+1)>=m||(i-1)<0||(j-1)<0||(j+1)>=n){
            valid = false;
        }
        visited[i][j] = 1;
        return 1+dfs(i+1,j,valid)+dfs(i-1,j,valid)+dfs(i,j+1,valid)+dfs(i,j-1,valid);
    }
    int closedIsland(vector<vector<int>>& grid) {
        this->m = grid.size();
        this->n = grid[0].size();
         vector<vector<bool>> visited(m,vector<bool>(n,false));
        this->visited = visited;
        this->grid = grid;
        int ans = 0;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(this->visited[i][j]==false&&grid[i][j]==0){
                    bool valid = true;
                    int curr = dfs(i,j,valid);
                    if(valid) ans+=1;
                }

            }
        }
        return ans;
    }
};
