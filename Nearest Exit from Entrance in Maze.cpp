/*

You are given an m x n matrix maze (0-indexed) with empty cells (represented as '.') and walls (represented as '+'). You are also given the entrance of the maze, where entrance = [entrancerow, entrancecol] denotes the row and column of the cell you are initially standing at.

In one step, you can move one cell up, down, left, or right. You cannot step into a cell with a wall, and you cannot step outside the maze. Your goal is to find the nearest exit from the entrance. An exit is defined as an empty cell that is at the border of the maze. The entrance does not count as an exit.

Return the number of steps in the shortest path from the entrance to the nearest exit, or -1 if no such path exists.


*/







class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();
        set<pair<int,int>> visited;
        queue<pair<int,int>> q;
        q.push({entrance[0],entrance[1]});
        int steps = 0;
        while(!q.empty()){
            int temp = q.size();
            for(int i =0;i<temp;i++){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                if(visited.find({x,y})!=visited.end()) continue;
                if(maze[x][y]=='.'&&(x==0||y==0||x==m-1||y==n-1)&&!(x==entrance[0]&&y==entrance[1])) return steps;
                if((x-1)>=0&&maze[x-1][y]!='+') q.push({x-1,y});
                if((y-1)>=0&&maze[x][y-1]!='+') q.push({x,y-1});
                if((x+1)<m&&maze[x+1][y]!='+') q.push({x+1,y});
                if((y+1)<n&&maze[x][y+1]!='+') q.push({x,y+1});
                
                visited.insert({x,y});
            }
            
          steps++;  
            
        }
        return -1;
    }
};
