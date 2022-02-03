
/*
Given an integer n, return true if n has exactly three positive divisors. Otherwise, return false.

An integer m is a divisor of n if there exists an integer k such that n = k * m.


*/


class Solution {
public:
    bool isThree(int n) {
        bool flag = true;
        for(int i = 2;i<n;i++){
            if(n%i==0){
                if(flag) flag = false;
                else return false;
            }
        }
        if(flag) return false;
        return true;
    }
};
