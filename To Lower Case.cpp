
/*
Given a string s, return the string after replacing every uppercase letter with the same lowercase letter.

100th EASY PROBLEM

*/




class Solution {
public:
    string toLowerCase(string s) {
        for(int i =0;i<s.size();i++){
            s[i] = (char)tolower(s[i]);
        }
        return s;
    }
};
