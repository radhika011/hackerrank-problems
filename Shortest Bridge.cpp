/*
You are given an n x n binary matrix grid where 1 represents land and 0 represents water.

An island is a 4-directionally connected group of 1's not connected to any other 1's. There are exactly two islands in grid.

You may change 0's to 1's to connect the two islands to form one island.

Return the smallest number of 0's you must flip to connect the two islands.

IDEA TO SET 2 TO 1s THAT HAVE ALREADY BEEN EXPLORED



*/





class Solution {
public:
    
    queue<pair<int,int>> qn;
    int n;
    vector<vector<int>> grid;
    set<pair<int,int>> visits;
   
    void dfs(int i,int j){
        if(i<0||j<0||i>=n||j>=n) return;
        if(visits.find({i,j})!=visits.end()) return;
        
        visits.insert({i,j});
        //cout<<visits.size()<<endl;
        if(grid[i][j]==0){
            //cout<<i<<" "<<j<<" "<<grid[i][j]<<endl;
            qn.push({i,j});
            return;
        }
        grid[i][j] = 2;
        dfs(i+1,j);
        dfs(i-1,j);
        dfs(i,j-1);
        dfs(i,j+1);
    }
    
    
    
    
    
    
    int shortestBridge(vector<vector<int>>& grid) {
        this->n = grid.size();
        this->grid = grid;
        set<pair<int,int>> visits;
        this->visits = visits;
        bool flag = false;
        for(int i =0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j]==1){
                    dfs(i,j);
                    flag = true;
                    break;
                }
            }
            if(flag) break;
        }
        
         queue<pair<int,int>> q;
        q = qn;
        //cout<<q.size()<<endl;
        set<pair<int,int>> visited;
       
        int steps = 0;
        
        while(!q.empty()){
            int temp = q.size();
            for(int i = 0;i<temp;i++){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                //cout<<x<<" "<<y<<endl;
                if(this->grid[x][y]==1){
                    
                    return steps;
                } 
                if(visited.find({x,y})!=visited.end()) continue;
                if((x-1)>=0) q.push({x-1,y});
                if((y-1)>=0) q.push({x,y-1});
                if((x+1)<n) q.push({x+1,y});
                if((y+1)<n) q.push({x,y+1});
                visited.insert({x,y});
            }
            steps++;
            
            
            
            
            
        }
        return -1;
    }
};
