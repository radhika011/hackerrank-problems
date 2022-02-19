

/*
Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
The '.' character indicates empty cells.





*/


class Solution {
public:
    bool checkFull(vector<vector<int>>& board){
    for(int i = 0;i<9;i++){
        for(int j =0;j<9;j++){
            if(board[i][j]==0) return false;
        }
    }
    return true;
}


bool checkCol(int i,int j,int k,vector<vector<int>>& board){
    for(int r = 0;r<9;r++){
        if(board[r][j]==k) return false;
    }
	return true;
}
bool checkRow(int i,int j,int k,vector<vector<int>>& board){
    for(int r = 0;r<9;r++){
        if(board[i][r]==k) return false;
    }
	return true;
}
bool checkBlock(int i,int j,int k,vector<vector<int>> board){
    int starti = i;
    for(;starti%3!=0;starti--);
    int startj = j;
    for(;startj%3!=0;startj--);
    for(int p = starti;p<(starti+3);p++){
        for(int q = startj;q<(startj+3);q++){
            if(board[p][q]==k) return false;
        }
    }
    return true;
    
    
    
}
    void printSolution(vector<vector<int>>& board){
        for(int i =0;i<9;i++){
            for(int j =0;j<9;j++){
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    
    
    void solveSudoku(vector<vector<char>>& board){
        int n = board.size();
        vector<vector<int>> boardi(9,vector<int>(9));
        for(int i =0;i<9;i++){
            for(int j =0;j<9;j++){
                if(board[i][j]=='.'){
                    boardi[i][j] = 0;
                    continue;
                }
                
                boardi[i][j] = board[i][j]-'0';
               // cout<<boardi[i][j]<<endl;
            }
        }
        vector<vector<int>> ans;
        solver(boardi,ans);
        for(int i =0;i<9;i++){
            for(int j =0;j<9;j++){
                string curr = to_string(ans[i][j]);
                board[i][j] = curr[0];
            }
        }
        
        
        
    }
    
    
    void solver(vector<vector<int>>& board,vector<vector<int>>& ans) {
        
         if(checkFull(board)){
             ans = board;
             //printSolution(board);
             return;
         }
        int i = 0;
        int j = 0;
        for(;i<9;i++){
            j = 0;
            bool flag = false;
            for(;j<9;j++){
            if(board[i][j]==0){
                flag = true;
                break;
            }
        }
        if(flag) break;
    }
    for(int k = 1;k<=9;k++){
        if(checkCol(i,j,k,board)&&
        checkRow(i,j,k,board)&&
        checkBlock(i,j,k,board)){
            board[i][j] = k;
            solver(board,ans);
            //if(nextSolve) return true;
            board[i][j] = 0;
        }
    }
   // return false;
    
    }
};
