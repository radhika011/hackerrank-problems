class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        int temp = x;
        double rev = 0;
        while(temp!=0){
            rev *= 10;
            int rem = temp%10;
            rev+=rem;
            temp = temp/10;
        }
        if(rev==x) return true;
        return false;
    }
};
