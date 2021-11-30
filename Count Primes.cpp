
/*


Given an integer n, return the number of prime numbers that are strictly less than n.




*/




class Solution {
public:
    void check(int i,vector<bool>& sieve,int n){
        for(int j= 2;i*j<n;j++){
            sieve[(i*j)] = false;
        }
    }
    
    
    int countPrimes(int n) {
        if(n==0) return 0;
        vector<bool> sieve(n,true);
        sieve[0] = false;
        sieve[1] = false;
        int count = 0;
        for(int i =2;i<n;i++){
            if(sieve[i]){
                check(i,sieve,n);
                count++;
            }
        }
        return count;
    }
};
