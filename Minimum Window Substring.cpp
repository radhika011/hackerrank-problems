/*
Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

A substring is a contiguous sequence of characters within the string.



*/






class Solution {
public:
    
    bool check(vector<int> phash,vector<int> hash){
        for(int i = 0;i<128;i++){
            if(phash[i]==0) continue;
            if(phash[i]>hash[i]) return false; 
        }
        return true;
    }
    
    
    string minWindow(string s, string t) {
       int n = s.size();
        if(s.size()<t.size()) return "";
        
        vector<int> phash(128,0);
        vector<int> hash(128,0);
        for(int i =0;i<t.size();i++){
            phash[t[i]]+=1;
        }
        
        int minLen = INT_MAX;
        string minString = "";
        int start = 0;
        int end = 0;
        
        while(end<n){
          //cout<<"1 "<<start<<" "<<end<<" "<<endl;
           
            while(end<n){
                
                hash[s[end]]+=1;
                 if(check(phash,hash)) break;
                end++;
            }
           //cout<<"2 "<<start<<" "<<end<<" "<<endl;
            //cout<<hash[67]<<endl;
            while(check(phash,hash)){
                //cout<<"3 "<<start<<" "<<end<<endl;
                int len = end-start+1;
               
                if(len<minLen){
                    
                    minLen = len;
                     
                    minString = s.substr(start,minLen);
                    //cout<<start<<" "<<minLen<<" "<<minString<<endl;
                }
                 hash[s[start]]-=1;
                
                start++;
            }
            end++;
        }
       
        return minString;
    }
};
