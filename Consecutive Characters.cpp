

/*

The power of the string is the maximum length of a non-empty substring that contains only one unique character.

Given a string s, return the power of s.

*/



class Solution {
public:
    int maxPower(string s) {
        int n = s.size();
        int gmax = 1;
        int lmax = 1;
        for(int i = 1;i<n;i++){
            if(s[i-1]==s[i]) lmax++;
            else lmax = 1;
            if(lmax>gmax){
                gmax = lmax;
            }
    }
        return gmax;
        }
};
