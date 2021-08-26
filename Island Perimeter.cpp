class Solution {
public:
    bool isOccupied(int i,int j,vector<vector<int>>& grid){
        if(i<0||j<0||i>=grid.size()||j>=grid[0].size()) return true;
        if(grid[i][j]==0) return false;
        return true;
    }
    void helper(int i,int j, vector<vector<int>>& grid,int &count,vector<vector<bool>>& visited){
        //cout<<i<<" "<<j<<endl;
        if(i>=0&&j>=0&&i<grid.size()&&j<grid[0].size()&&!visited[i][j]){
            if(grid[i][j]==1){
                
                visited[i][j] = true;
                if((i-1)<0) count++;
                if((j-1)<0) count++;
                if((i+1)==grid.size()) count++;
                if((j+1)==grid[0].size()) count++;
                if(!isOccupied(i+1,j,grid)) count++;
                if(!isOccupied(i,j+1,grid)) count++;
                if(!isOccupied(i-1,j,grid)) count++;
                if(!isOccupied(i,j-1,grid)) count++;
                helper(i+1,j,grid,count,visited);
        helper(i,j+1,grid,count,visited);
        helper(i-1,j,grid,count,visited);
        helper(i,j-1,grid,count,visited);
            }
            
        }
        //cout<<count<<endl;
        
        return;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int h = grid.size();
        int w = grid[0].size();
        int count =0;
        vector<vector<bool>> visited(h,vector<bool>(w,false));
        for(int i = 0;i<h;i++){
            for(int j =0;j<w;j++){
                if(grid[i][j]==1){
                    //cout<<i<<" "<<j<<endl;
                    helper(i,j,grid,count,visited);
                    break;
                }
            }
        }
        return count;
        
        
    }
};
