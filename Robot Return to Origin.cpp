class Solution {
public:
    bool judgeCircle(string moves) {
        int rowIndex = 0;
        int colIndex = 0;
        for(int i = 0;i<moves.size();i++){
            char currMove = moves[i];
            if(currMove=='U') rowIndex-=1;
            else if(currMove=='D') rowIndex+=1;
            else if(currMove=='L') colIndex-=1;
            else colIndex+=1;
        }
        if(rowIndex==0&&colIndex==0) return true;
        return false;
    }
};
