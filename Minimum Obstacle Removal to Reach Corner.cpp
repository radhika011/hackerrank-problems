/*
You are given a 0-indexed 2D integer array grid of size m x n. Each cell has one of two values:

0 represents an empty cell,
1 represents an obstacle that may be removed.
You can move up, down, left, or right from and to an empty cell.

Return the minimum number of obstacles to remove so you can move from the upper left corner (0, 0) to the lower right corner (m - 1, n - 1).



*/




class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> q;
        q.push({0,{0,0}});
        int ans = 0;
        set<pair<int,int>> visited;
        while(!q.empty()){
            ans = q.top().first;
            int x = q.top().second.first;
            int y = q.top().second.second;
            q.pop();
            if(x==(m-1)&&y==(n-1)) return ans;
            //option 1 - (x-1,y)
            if((x-1)>=0&&visited.find({x-1,y})==visited.end()){
                if(grid[x-1][y]==1){
                    q.push({ans+1,{x-1,y}});
                }
                else{
                    q.push({ans,{x-1,y}});
                }
                visited.insert({x-1,y});
            }
            
            
            //option 2 - (x,y-1)
             if((y-1)>=0&&visited.find({x,y-1})==visited.end()){
                if(grid[x][y-1]==1){
                    q.push({ans+1,{x,y-1}});
                }
                else{
                    q.push({ans,{x,y-1}});
                }
                  visited.insert({x,y-1});
            }
            
            
            
            //option 3 - (x+1,y)
             if((x+1)<m&&visited.find({x+1,y})==visited.end()){
                if(grid[x+1][y]==1){
                    q.push({ans+1,{x+1,y}});
                }
                else{
                    q.push({ans,{x+1,y}});
                }
                  visited.insert({x+1,y});
            }
            
            
            //option 4 - (x,y+1)
             if((y+1)<n&&visited.find({x,y+1})==visited.end()){
                if(grid[x][y+1]==1){
                    q.push({ans+1,{x,y+1}});
                }
                else{
                    q.push({ans,{x,y+1}});
                }
                  visited.insert({x,y+1});
            }
            
        }
        
        
        
        
        
        return ans;
    }
};
