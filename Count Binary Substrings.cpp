/*
Give a binary string s, return the number of non-empty substrings that have the same number of 0's and 1's, and all the 0's and all the 1's in these substrings are grouped consecutively.

Substrings that occur multiple times are counted the number of times they occur.






*/



class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.size();
        int zeros = 0;
        int ans = 0;
        bool prev = true;
        for(int i = 0;i<n;i++){
            int curr = s[i]-'0';
            if(curr==0&&!prev){
                prev = true;
                zeros = 0;
            }
            if(curr==0) zeros++;
            else{
                if(zeros>0){
                    ans++;
                    zeros--;
                }
                prev = false;
            }
        }
        zeros = 0;
         prev = true;
        for(int i = 0;i<n;i++){
            int curr = s[i]-'0';
            if(curr==1&&!prev){
                prev = true;
                zeros = 0;
            }
            if(curr==1) zeros++;
            else{
                if(zeros>0){
                    ans++;
                    zeros--;
                }
                prev = false;
            }
        }
        return ans;
        
    }
};
