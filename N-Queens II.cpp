/*




The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return the number of distinct solutions to the n-queens puzzle.



*/





class Solution {
public:
    
    int n;
   int ans;
    Solution(){
        ans = 0;
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
           ans++;
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
    
    
    
    int totalNQueens(int n) {
        set<pair<int,int>> board;
        this->n = n;
        vector<int> visited(n,0);
        helper(0,board,visited);
        return ans;
    }
};
