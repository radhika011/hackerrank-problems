/*
Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.



*/




class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        vector<int> phash(26,0);
        vector<int> hash(26,0);
        if(n>s2.size()) return false;
        for(int i = 0;i<n;i++){
            int curr = s1[i]-97;
            phash[curr] +=1;
        }
        for(int i = 0;i<n-1;i++){
            int curr = s2[i]-97;
            hash[curr]+=1;
        }
        int start = 0;
        int end = n-1;
        while(end<s2.size()){
            int endChar = s2[end]-97; 
            hash[endChar]+=1;
            if(hash==phash) return true;
            int startChar = s2[start]-97;
            hash[startChar]-=1;
            start++;
            end++;
        }
        return false;
    }
};
