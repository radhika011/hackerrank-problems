/*
Given an integer n, return true if it is a power of three. Otherwise, return false.

An integer n is a power of three, if there exists an integer x such that n == 3x.




*/





class Solution {
public:
    bool isPowerOfThree(int n) {
        int curr = n;
        if(n==0) return false;
        while(curr!=1){
            if(curr%3!=0) return false;
            curr /= 3;
        }
        return true;
    }
};
