
/*
There is an n x n grid, with the top-left cell at (0, 0) and the bottom-right cell at (n - 1, n - 1). You are given the integer n and an integer array startPos where startPos = [startrow, startcol] indicates that a robot is initially at cell (startrow, startcol).

You are also given a 0-indexed string s of length m where s[i] is the ith instruction for the robot: 'L' (move left), 'R' (move right), 'U' (move up), and 'D' (move down).

The robot can begin executing from any ith instruction in s. It executes the instructions one by one towards the end of s but it stops if either of these conditions is met:

The next instruction will move the robot off the grid.
There are no more instructions left to execute.
Return an array answer of length m where answer[i] is the number of instructions the robot can execute if the robot begins executing from the ith instruction in s.




*/



class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
       
        int maxPos = s.size();
        vector<int> ans(maxPos,0);
        for(int i =0;i<maxPos;i++){
             int x1 = startPos[0];
            int y1 = startPos[1];
            int stepsPos = 0;
            for(int j = i;j<maxPos;j++){
                char currInst = s[j];
                if(currInst=='R'){
                    if(y1==n-1) break;
                    y1++;
                }
                if(currInst=='L'){
                    if(y1==0) break;
                    y1--;
                }
                if(currInst=='U'){
                    if(x1==0) break;
                    x1--;
                }
                if(currInst=='D'){
                    if(x1==n-1) break;
                    x1++;
                }
                stepsPos++;
            }
            ans[i] = stepsPos;
            
            
        }
        return ans;
    }
};
