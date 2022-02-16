/*
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.





*/





class Solution {
public:
      int n;
   vector<vector<string>> ans;
    Solution(){
        
    }
    
    
    bool check(int i,int j, set<pair<int,int>> board){
        for(auto it = board.begin();it!=board.end();it++){
            int currX = abs(it->first-i);
            int currY = abs(it->second-j);
            if(currX==currY) return false;
        }
        return true;
    }
    
    
    void helper(int curr, set<pair<int,int>> board,vector<int> visited){
        if(curr==n){
            string init = "";
            for(int i = 0;i<n;i++){
                init+=".";
            }
           vector<string> part(n,init);
            for(auto it = board.begin();it!=board.end();it++){
                part[it->first][it->second] = 'Q';
            }
            ans.push_back(part);
            return;
        }
        for(int i = 0;i<n;i++){
            if(visited[i]==1) continue;
            if(!check(curr,i,board)) continue; 
            visited[i] =1;
           
            set<pair<int,int>> temp = board;
            temp.insert({curr,i});
            helper(curr+1,temp,visited);
            visited[i] = 0;
            
        }
    }
    
    
    vector<vector<string>> solveNQueens(int n) {
        set<pair<int,int>> board;
        this->n = n;
        vector<int> visited(n,0);
        helper(0,board,visited);
        return ans;
    }
};
