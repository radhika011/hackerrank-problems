/*
You are given two strings of the same length s and t. In one step you can choose any character of t and replace it with another character.

Return the minimum number of steps to make t an anagram of s.

An Anagram of a string is a string that contains the same characters with a different (or the same) ordering.






*/



class Solution {
public:
    int minSteps(string s, string t) {
        int n = s.size();
        vector<int> shash(26,0);
        vector<int> thash(26,0);
        for(int i =0;i<n;i++){
            int currS = s[i]-97;
            int currT = t[i]-97;
            shash[currS]+=1;
            thash[currT]+=1;
        }
        int ans = 0;
        for(int i =0;i<26;i++){
            if(shash[i]==0) continue;
            if(shash[i]<=thash[i]) continue;
            ans+=abs(shash[i]-thash[i]);
            //cout<<ans<<endl;
        }
        return ans;
    }
};
