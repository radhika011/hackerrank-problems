/*
Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.

Each letter in magazine can only be used once in ransomNote.





*/








class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int n = magazine.size();
        vector<int> counts(26,0);
        for(int i = 0;i<n;i++){
            counts[magazine[i]-97]+=1;
        }
        for(int i = 0;i<ransomNote.size();i++){
            if(counts[ransomNote[i]-97]==0) return false;
            counts[ransomNote[i]-97]-=1;
        }
        return true;
    }
};
