/*
You are given a 0-indexed string text and another 0-indexed string pattern of length 2, both of which consist of only lowercase English letters.

You can add either pattern[0] or pattern[1] anywhere in text exactly once. Note that the character can be added even at the beginning or at the end of text.

Return the maximum number of times pattern can occur as a subsequence of the modified text.

A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.


*/




typedef long long ll;
class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) {
        int n = text.size();
        ll subsqCount1 = 0;
        ll no1 = 0;
        string text1 = text+pattern[1];
        for(int i = 0;i<n+1;i++){
            if(text1[i]==pattern[0]){
                no1++;
                continue;
            }
            if(text1[i]==pattern[1]){
                subsqCount1+=no1;
            }
        }
        if(pattern[0]==pattern[1]){
            subsqCount1+=((no1-1)*no1)/2;
        }
        
         ll subsqCount2 = 0;
        ll no2 = 0;
        string text2 = pattern[0]+text;
        for(int i = 0;i<n+1;i++){
            if(text2[i]==pattern[0]){
                no2++;
                continue;
            }
            if(text2[i]==pattern[1]){
                subsqCount2+=no2;
            }
        }
        if(pattern[0]==pattern[1]){
            subsqCount2+=((no2-1)*no2)/2;
        }
        
       
        return max(subsqCount1,subsqCount2);
        
    }
};
