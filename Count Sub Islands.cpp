/*
You are given two m x n binary matrices grid1 and grid2 containing only 0's (representing water) and 1's (representing land). An island is a group of 1's connected 4-directionally (horizontal or vertical). Any cells outside of the grid are considered water cells.

An island in grid2 is considered a sub-island if there is an island in grid1 that contains all the cells that make up this island in grid2.

Return the number of islands in grid2 that are considered sub-islands.



*/




class Solution {
public:
    vector<vector<int>> grid2;
    int m,n;
    vector<vector<bool>> visited;
    vector<vector<int>> grid1;
    void dfs(int i,int j,bool& isSub){
        if(i<0||j<0||i>=m||j>=n){
            return;
        }
        if(grid2[i][j]==0) return;
        if(visited[i][j]) return;
        visited[i][j] = true;
        if(grid1[i][j]==0){
            isSub = false;
        }
        dfs(i+1,j,isSub);
        dfs(i-1,j,isSub);
        dfs(i,j-1,isSub);
        dfs(i,j+1,isSub);
    }
    /*
    bool compare(vector<vector<int>>& grid1, vector<vector<int>>& curr){
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(curr[i][j]==1&&grid1[i][j]==0) return false;
            }
        }
        return true;
        
        
    }
    */
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        this->m = grid1.size();
        this->grid1 = grid1;
        this->n = grid1[0].size();
        int ans = 0;
        vector<vector<bool>> visit(m,vector<bool>(n,false));
        this->visited = visit;
        this->grid2 = grid2;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid2[i][j]==1&&!visited[i][j]){
                    bool isSub = true;
                    dfs(i,j,isSub);
                    //bool same = compare(grid1,curr);
                    //cout<<i<<" "<<j<<" "<<same<<endl;
                    if(isSub) ans+=1;
                }
            }
        }
        return ans;
    }
};
