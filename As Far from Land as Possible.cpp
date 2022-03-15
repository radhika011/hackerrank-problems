/*
Given an n x n grid containing only values 0 and 1, where 0 represents water and 1 represents land, find a water cell such that its distance to the nearest land cell is maximized, and return the distance. If no land or water exists in the grid, return -1.

The distance used in this problem is the Manhattan distance: the distance between two cells (x0, y0) and (x1, y1) is |x0 - x1| + |y0 - y1|.



*/





class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid[0].size();
        queue<pair<int,int>> q;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j]==1){
                    q.push({i-1,j});
                    q.push({i+1,j});
                    q.push({i,j-1});
                    q.push({i,j+1});
                }
            }
        }
        if(q.size()==0) return -1;
        int ans = INT_MIN;
        int steps = 0;
        while(!q.empty()){
            steps++;
            int temp = q.size();
            for(int i = 0;i<temp;i++){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                if(x>=0&&x<n&&y>=0&&y<n&&grid[x][y]==0){
                    grid[x][y] = steps;
                    ans = max(ans,steps);
                    q.push({x-1,y});
                    q.push({x+1,y});
                    q.push({x,y-1});
                    q.push({x,y+1});
                }
            }
        }
        return max(-1,ans);
    }
};
