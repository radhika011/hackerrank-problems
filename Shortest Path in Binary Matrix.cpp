/*

Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.

A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:

All the visited cells of the path are 0.
All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).
The length of a clear path is the number of visited cells of this path.



*/




class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int,int>> q;
        if(grid[0][0]==1||grid[n-1][n-1]==1) return -1;
        q.push({0,0});
        int steps = 0;
        bool flag = false;
        while(!q.empty()){
            int temp = q.size();
             //cout<<"hello"<<endl;
            steps++;
            for(int i = 0;i<temp;i++){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                if(x>=0&&x<n&&y>=0&&y<n&&grid[x][y]==0){
                    grid[x][y] = steps;
                    if(x==n-1&&y==n-1){
                       
                        flag = true;
                        break;
                    }
                    q.push({x+1,y});
                     q.push({x-1,y});
                     q.push({x,y-1});
                     q.push({x,y+1});
                     q.push({x+1,y-1});
                     q.push({x+1,y+1});
                     q.push({x-1,y-1});
                     q.push({x-1,y+1});
                }
            }
        
            
            
            
        }
        if(flag) return grid[n-1][n-1];
        return -1;
    }
};
