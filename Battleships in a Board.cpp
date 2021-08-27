class Solution {
public:
    void dfs(vector<vector<bool>>& visited,vector<vector<char>>& board,int i,int j){
        if(i>=0&&j>=0&&i<board.size()&&j<board[0].size()&&!visited[i][j]&&board[i][j]=='X'){
            visited[i][j] =true;
            dfs(visited,board,i+1,j);
            dfs(visited,board,i,j+1);
            dfs(visited,board,i-1,j);
            dfs(visited,board,i,j-1);
        }
    }
    int countBattleships(vector<vector<char>>& board) {
        int count = 0;
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        for(int i =0;i<m;i++){
            for(int j =0;j<n;j++){
                if(board[i][j]=='X'&&!visited[i][j]){
                    count++;
                    dfs(visited,board,i,j);
                    
                }
            }
        }
        return count;
    }
};
