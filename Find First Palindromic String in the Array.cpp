/*


Given an array of strings words, return the first palindromic string in the array. If there is no such string, return an empty string "".

A string is palindromic if it reads the same forward and backward.

EASY AF - DON'T EVEN BOTHER

*/




class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        int n = words.size();
        int i =0;
        for(;i<n;i++){
            string curr = words[i];
            reverse(curr.begin(),curr.end());
            if(curr==words[i]) break;
        }
        if(i==n) return "";
        return words[i];
    }
};
