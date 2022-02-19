/*
Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
Note:

A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.



*/







class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        for(int i = 0;i<n;i++){
            unordered_set<char> visited;
            for(int j = 0;j<n;j++){
                if(board[i][j]=='.') continue;
                if(visited.find(board[i][j])!=visited.end()) return false;
                visited.insert(board[i][j]);
            }
        }
       
        for(int j = 0;j<n;j++){
            unordered_set<char> visited;
            for(int i = 0;i<n;i++){
                if(board[i][j]=='.') continue;
                if(visited.find(board[i][j])!=visited.end()) return false;
                visited.insert(board[i][j]);
            }
        }
        
        for(int i = 0;i<n;i+=3){
            for(int j = 0;j<n;j+=3){
                unordered_set<char> visited;
                for(int k = 0;k<3;k++){
                    for(int l = 0;l<3;l++){
                         if(board[k+i][j+l]=='.') continue;
                         if(visited.find(board[k+i][j+l])!=visited.end()) {
                             
                             return false;
                         }
                         visited.insert(board[k+i][j+l]);
                    }
                }
            }
        }
        
        return true;
        
    }
};
