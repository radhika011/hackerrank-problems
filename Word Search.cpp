//DFS and Backtracking approach
class Solution {
public:
    bool helper(int i,int j,vector<vector<char>>& board,string word,int strPtr,vector<vector<bool>> &visited){
        int m = board.size();
        int n = board[0].size();
        int len = word.size();
        //cout<<i<<" "<<j<<" "<<strPtr<<endl; -> caused TLE
        if(strPtr==len) return false;
        if(i<m&&j<n&&j>=0&&i>=0&&visited[i][j]==false){
            if(board[i][j]==word[strPtr]&&strPtr==(len-1)) return true;
            if(board[i][j]==word[strPtr]){
                //cout<<i<<" "<<j<<" "<<strPtr<<" "<<endl;
                strPtr = strPtr+1;
                visited[i][j] = true;
                bool d1 = helper(i+1,j,board,word,strPtr,visited);
                bool d2 = helper(i,j+1,board,word,strPtr,visited);
                bool d3 = helper(i,j-1,board,word,strPtr,visited);
                bool d4 = helper(i-1,j,board,word,strPtr,visited);
                if(d1||d2||d3||d4){
                    return d1||d2||d3||d4;
                }
                visited[i][j] = false;
            }
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        bool flag = false;
        for(int i =0;i<m;i++){
            for(int j =0;j<n;j++){
                vector<vector<bool>> visited(m,vector<bool>(n,false));
                bool curr = helper(i,j,board,word,0,visited);
                if(curr){
                    flag = true;
                    break;
                } 
            }
            
        }
        return flag;
    }
};
