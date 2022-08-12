/*


You are given a map of a server center, represented as a m * n integer matrix grid, where 1 means that on that cell there is a server and 0 means that it is no server. Two servers are said to communicate if they are on the same row or on the same column.

Return the number of servers that communicate with any other server.



*/






class Solution {
public:
    
    int m,n;
    vector<vector<int>> grid;
    
    int dfs(int i,int j,vector<vector<int>>& visited){
        if(i>=m||i<0||j>=n||j<0) return 0;
        if(grid[i][j]==0) return 0;
        int curr = 0;
        if(visited[i][j]!=-1) return 0;
        visited[i][j] = 1;
        //cout<<i<<" "<<j<<endl;
        for(int x = 0;x<m;x++){
            if(grid[x][j]==1&&x!=i){
                //cout<<"xj "<<x<<" "<<j<<endl;
                curr = curr+dfs(x,j,visited);
                grid[x][j] = -1;
            }
        }
        for(int x = 0;x<n;x++){
            if(grid[i][x]==1&&x!=j){
                curr = curr+dfs(i,x,visited);
                grid[i][x] = -1;
            }
        }
        //cout<<curr<<endl;
        if(curr==0) return 1;
        return 1+curr;
    }
    
    
    
    
    
    int countServers(vector<vector<int>>& grid) {
        this->m = grid.size();
        this->n = grid[0].size();
        int ans = 0;
        this->grid = grid;
        vector<vector<int>> visited(m,vector<int>(n,-1));
        for(int i =0;i<m;i++){
            for(int j =0;j<n;j++){
                int curr = grid[i][j];
                if(curr==1){
                    int canComm = dfs(i,j,visited);
                   if(canComm==1) canComm = 0;
                    ans+=canComm;
                }
            }
        }
        return ans;
    }
}; 
