
/*

Given a string s consisting of lowercase English letters, return the first letter to appear twice.

Note:

A letter a appears twice before another letter b if the second occurrence of a is before the second occurrence of b.
s will contain at least one letter that appears twice.



*/




class Solution {
public:
    char repeatedCharacter(string s) {
        set<char> appeared;
        int n = s.size();
        for(int i =0;i<n;i++){
            char currChar = s[i];
            if(appeared.find(currChar)!=appeared.end()) return currChar;
            appeared.insert(currChar);
        }
        return 'x';
    }
};
