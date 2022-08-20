
/*

You are given a string s of lowercase English letters and a 2D integer array shifts where shifts[i] = [starti, endi, directioni]. For every i, shift the characters in s from the index starti to the index endi (inclusive) forward if directioni = 1, or shift the characters backward if directioni = 0.

Shifting a character forward means replacing it with the next letter in the alphabet (wrapping around so that 'z' becomes 'a'). Similarly, shifting a character backward means replacing it with the previous letter in the alphabet (wrapping around so that 'a' becomes 'z').

Return the final string after all such shifts to s are applied.



*/







class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = shifts.size();
        vector<int> dp(s.size()+1,0);
        for(int i = 0;i<n;i++){
            int start = shifts[i][0];
            int end = shifts[i][1];
            int dir = shifts[i][2];
            if(dir==1){
                dp[start] += 1;
                dp[end+1] += (-1);
            }
            else{
                dp[start] += (-1);
                dp[end+1] += 1;
            }
        }
        string ans = "";
        int sumupto = 0;
        for(int i = 0;i<s.size();i++){
            sumupto+=dp[i];
            int curr = s[i];
            int norm = -1;
            
           
            int newcurr = curr;
            
            newcurr+=((sumupto)%26);
           
            char normalized = newcurr;
           // cout<<(int)newcurr<<endl;
            if(newcurr>122){
                normalized = (newcurr-122)+96;
            }
            if(newcurr<97){
                normalized = newcurr+26;
            }
           // cout<<curr<<" "<<(int)newcurr<<" "<<(int)normalized<<endl;
            
            ans+=normalized;
        }
        return ans;
    }
};
