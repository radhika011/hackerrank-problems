
/*
Given a string s, find the length of the longest substring without repeating characters.



*/


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        vector<int> hash(128,-1);
        int start = 0;
        int end = 0;
        int ans = 0;
        while(end<n){
            int curr = s[end];
            if(hash[curr]!=-1){
                //cout<<hash[curr]<<endl;
                start = max(start,hash[curr]+1); //to make sure that we don't go back
                
            }
             int currLen = end-start+1;
            //cout<<currLen<<" "<<start<<" "<<end<<" "<<s[end]<<" "<<hash[curr]<<endl;
            hash[curr] = end;
           
            ans = max(ans,currLen);
            
            end++;
            
            
        }
        return ans;
    }
};
