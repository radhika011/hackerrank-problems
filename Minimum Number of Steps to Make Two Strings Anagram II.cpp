/*
You are given two strings s and t. In one step, you can append any character to either s or t.

Return the minimum number of steps to make s and t anagrams of each other.

An anagram of a string is a string that contains the same characters with a different (or the same) ordering.



*/



class Solution {
public:
    int minSteps(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();
        vector<int> h1(128,0);
        vector<int> h2(128,0);
        for(int i = 0;i<n1;i++){
            h1[s[i]]++;
        }
        for(int i = 0;i<n2;i++){
            h2[t[i]]++;
        }
        int ans = 0;
        for(int i = 0;i<128;i++){
            ans+=abs(h1[i]-h2[i]);
        }
        return ans;
    }
};
