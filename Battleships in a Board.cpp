/*

Given an m x n matrix board where each cell is a battleship 'X' or empty '.', return the number of the battleships on board.

Battleships can only be placed horizontally or vertically on board. In other words, they can only be made of the shape 1 x k (1 row, k columns) or k x 1 (k rows, 1 column), where k can be of any size. At least one horizontal or vertical cell separates between two battleships (i.e., there are no adjacent battleships).


REVIEW 1 DONE



*/


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
