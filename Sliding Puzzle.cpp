/*

On an 2 x 3 board, there are five tiles labeled from 1 to 5, and an empty square represented by 0. A move consists of choosing 0 and a 4-directionally adjacent number and swapping it.

The state of the board is solved if and only if the board is [[1,2,3],[4,5,0]].

Given the puzzle board board, return the least number of moves required so that the state of the board is solved. If it is impossible for the state of the board to be solved, return -1.






*/







class Solution {
public:
    
    
    
    void addToQueue(vector<vector<int>> curr,queue<vector<vector<int>>>& q){
        int m = curr.size();
        int n = curr[0].size();
        int x = -1;
        int y = -1;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(curr[i][j]==0){
                    x = i;
                    y = j;
                }
            }
        }
        vector<vector<int>> p1 = curr;
        if((x-1)>=0){
            int temp = p1[x-1][y];
            p1[x-1][y] = p1[x][y];
            p1[x][y] = temp;
            q.push(p1);
        }
        vector<vector<int>> p2 = curr;
        if((y-1)>=0){
            int temp = p2[x][y-1];
            p2[x][y-1] = p2[x][y];
            p2[x][y] = temp;
            q.push(p2);
        }
        vector<vector<int>> p3 = curr;
        if((x+1)<m){
            int temp = p3[x+1][y];
            p3[x+1][y] = p3[x][y];
            p3[x][y] = temp;
            q.push(p3);
        }
         vector<vector<int>> p4 = curr;
        if((y+1)<n){
            int temp = p4[x][y+1];
            p4[x][y+1] = p4[x][y];
            p4[x][y] = temp;
            q.push(p4);
        }
        
    }
    
    
    
    int slidingPuzzle(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> goal = {{1,2,3},{4,5,0}};
        set<vector<vector<int>>> visited;
        queue<vector<vector<int>>> q;
        q.push(board);
        int steps = 0;
        while(!q.empty()){
            int temp = q.size();
            for(int i =0;i<temp;i++){
                vector<vector<int>> curr = q.front();
                q.pop();
                if(curr==goal) return steps;
                if(visited.find(curr)!=visited.end()) continue;
                visited.insert(curr);
                addToQueue(curr,q);
            }
            
            steps++;    
        }
        return -1;
    }
};
