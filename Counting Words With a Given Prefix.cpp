/*
You are given an array of strings words and a string pref.

Return the number of strings in words that contain pref as a prefix.

A prefix of a string s is any leading contiguous substring of s.



*/



class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int n = words.size();
        int ans = 0;
        for(int i = 0;i<n;i++){
            string word = words[i];
            int j = 0;
            for(;j<word.size()&&j<pref.size();j++){
                if(pref[j]!=word[j]) break; 
            }
            if(j<pref.size()) continue;
            ans++;
        }
        
        
        return ans;
        
        
        
    }
};
