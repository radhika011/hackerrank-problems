/*
Given a m x n binary matrix mat. In one step, you can choose one cell and flip it and all the four neighbors of it if they exist (Flip is changing 1 to 0 and 0 to 1). A pair of cells are called neighbors if they share one edge.

Return the minimum number of steps required to convert mat to a zero matrix or -1 if you cannot.

A binary matrix is a matrix with all cells equal to 0 or 1 only.

A zero matrix is a matrix with all cells equal to 0.

BFS: VERY LOW CONSTRAINTS


*/



class Solution {
public:
    
    
    
    void addToQueue(int j,int k, queue<vector<vector<int>>> &q,vector<vector<int>> curr){
        int m = curr.size();
        int n = curr[0].size();
        curr[j][k] = (curr[j][k]+1)%2;
        if((j-1)>=0){
            curr[j-1][k] = (curr[j-1][k]+1)%2;
        }
        if((k-1)>=0){
            curr[j][k-1] = (curr[j][k-1]+1)%2;
        }
        if(j+1<m){
            curr[j+1][k] = (curr[j+1][k]+1)%2;
        }
        if(k+1<n){
            curr[j][k+1] = (curr[j][k+1]+1)%2;
        }
        q.push(curr);
        
        
    }
    void printMatrix(vector<vector<int>> curr){
        int m = curr.size();
        int n = curr[0].size();
        for(int i =0;i<m;i++){
            for(int j = 0;j<n;j++){
                cout<<curr[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    
    
    int minFlips(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        queue<vector<vector<int>>> q;
        int steps = 0;
        vector<vector<int>> zeros(m,vector<int>(n,0));
        q.push({mat});
        set<vector<vector<int>>> visited;
        while(!q.empty()){
            int temp = q.size();
            for(int i =0;i<temp;i++){
                vector<vector<int>> curr = q.front();
                q.pop();
                //printMatrix(curr);
                if(curr==zeros) return steps;
                if(visited.find(curr)!=visited.end()) continue;
                visited.insert(curr);
                for(int j = 0;j<m;j++){
                    for(int k =0;k<n;k++){
                        addToQueue(j,k,q,curr);
                    }
                }
            }
            //cout<<q.size()<<endl;
            steps++;
        }
        return -1;
    }
};
