class Solution {
public:
    int guessNumber(int n) {
        int start = 1;
        int end = n;
        int mid = 0;
        while(true){
            mid = ((start-end)/2)+end;
            if(guess(mid)==-1) end = mid-1;
            else if(guess(mid)==1) start = mid+1;
            if(guess(mid)==0) break;
        }
        return mid;
    }
};
