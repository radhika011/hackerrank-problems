class Solution {
public:
    int rec(int remCoins,int currRow){
        if(remCoins<currRow){
            return 0;
        }
        return 1+rec(remCoins-currRow,currRow+1);
    }
    
    
    
    
    
    int arrangeCoins(int n) {
        return rec(n,1);
    }
};
