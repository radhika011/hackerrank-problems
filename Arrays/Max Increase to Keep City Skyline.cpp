class Solution {
public:
    int helper(int row,int col,vector<vector<int>>& grid){
        int max1 = INT_MIN;
        for(int i = 0;i<grid.size();i++){
            if(grid[i][col]>max1) max1 = grid[i][col];
        }
        int max2 = INT_MIN;
        for(int i =0;i<grid[0].size();i++){
            if(grid[row][i]>max2) max2 = grid[row][i];
        }
        return min(max1,max2);
    }
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int sum = 0;
        for(int i = 0;i<grid.size();i++){
            for(int j =0;j<grid[0].size();j++){
                sum+=abs(helper(i,j,grid)-grid[i][j]);
            }
        }
        return sum;
        
    }
};
