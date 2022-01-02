/*

Given a string s consisting of only the characters 'a' and 'b', return true if every 'a' appears before every 'b' in the string. Otherwise, return false.

*/




class Solution {
public:
    bool checkString(string s) {
        bool b_detected = false;
        for(int i =0;i<s.size();i++){
            if(s[i]=='b'){
                b_detected = true;
            }
            else{
                if(b_detected) return false;
            }
        }
        return true;
    }
};
