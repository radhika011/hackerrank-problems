/*

There is an m x n rectangular island that borders both the Pacific Ocean and Atlantic Ocean. The Pacific Ocean touches the island's left and top edges, and the Atlantic Ocean touches the island's right and bottom edges.

The island is partitioned into a grid of square cells. You are given an m x n integer matrix heights where heights[r][c] represents the height above sea level of the cell at coordinate (r, c).

The island receives a lot of rain, and the rain water can flow to neighboring cells directly north, south, east, and west if the neighboring cell's height is less than or equal to the current cell's height. Water can flow from any cell adjacent to an ocean into the ocean.

Return a 2D list of grid coordinates result where result[i] = [ri, ci] denotes that rain water can flow from cell (ri, ci) to both the Pacific and Atlantic oceans.



*/





class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> pacific(m,vector<int>(n,0));
        vector<vector<int>> atlantic(m,vector<int>(n,0));
        for(int i = 0;i<m;i++){
            q.push({i,0});
        }
         for(int i = 0;i<n;i++){
            q.push({0,i});
        }
       
        vector<vector<int>> ans;
        set<pair<int,int>> visited;
        while(!q.empty()){
             
            int temp = q.size();
            for(int i =0;i<temp;i++){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                 
                if(visited.find({x,y})!=visited.end()) continue;
                if((x-1)>=0&&heights[x-1][y]>=heights[x][y]) q.push({x-1,y});
                if((y-1)>=0&&heights[x][y-1]>=heights[x][y]) q.push({x,y-1});
                if((x+1)<m&&heights[x+1][y]>=heights[x][y]) q.push({x+1,y});
                if((y+1)<n&&heights[x][y+1]>=heights[x][y]) q.push({x,y+1});
                visited.insert({x,y});
                //cout<<"here"<<x<<" "<<y<<endl;
                pacific[x][y] = 1;
            }
            
            
        }
       
        visited.clear();
        for(int i = 0;i<m;i++){
            q.push({i,n-1});
        }
         for(int i = 0;i<n;i++){
            q.push({m-1,i});
        }
        while(!q.empty()){
            int temp = q.size();
            for(int i =0;i<temp;i++){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                if(visited.find({x,y})!=visited.end()) continue;
                if((x-1)>=0&&heights[x-1][y]>=heights[x][y]) q.push({x-1,y});
                if((y-1)>=0&&heights[x][y-1]>=heights[x][y]) q.push({x,y-1});
                if((x+1)<m&&heights[x+1][y]>=heights[x][y]) q.push({x+1,y});
                if((y+1)<n&&heights[x][y+1]>=heights[x][y]) q.push({x,y+1});
                visited.insert({x,y});
                //cout<<"here"<<x<<" "<<y<<endl;
                atlantic[x][y] = 1;
            }
            
            
        }
        for(int i =0;i<m;i++){
            for(int j =0;j<n;j++){
                if(atlantic[i][j]==1&&pacific[i][j]==1){
                     vector<int> curr = {i,j};
                    ans.push_back(curr);
                }
            }
        }
       
        return ans;
        
    }
};
