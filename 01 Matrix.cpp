/*

Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.


*/





class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int,int>> q;
        int m = mat.size();
        int n = mat[0].size();
        set<pair<int,int>> visited;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                bool isLandlocked = true;
                if(mat[i][j]==0) continue;
                if((i-1)>=0&&mat[i-1][j]==0) isLandlocked = false;
                if((i+1)<m&&mat[i+1][j]==0) isLandlocked = false;
                if((j-1)>=0&&mat[i][j-1]==0) isLandlocked = false;
                if((j+1)<n&&mat[i][j+1]==0) isLandlocked = false;
                if(!isLandlocked){
                   // cout<<i<<" "<<j<<endl;
                    q.push({i,j});
                    //visited.insert({i,j});
                }
            }
        }
        int steps = 0;
        while(!q.empty()){
            int temp = q.size();
            steps++;
            for(int i = 0;i<temp;i++){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                if(x>=0&&x<m&&y>=0&&y<n&&mat[x][y]==1&&visited.find({x,y})==visited.end()){
                    mat[x][y] = steps;
                    visited.insert({x,y});
                    q.push({x-1,y});
                     q.push({x+1,y});
                     q.push({x,y-1});
                     q.push({x,y+1});
                }
            }
        }
        return mat;
    }
};
