/*
The DNA sequence is composed of a series of nucleotides abbreviated as 'A', 'C', 'G', and 'T'.

For example, "ACGAATTCCG" is a DNA sequence.
When studying DNA, it is useful to identify repeated sequences within the DNA.

Given a string s that represents a DNA sequence, return all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule. You may return the answer in any order.



*/



class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.size();
        vector<string> ans;
        if(n<10) return ans;
        set<string> rep;
        set<string> memo;
        int start = 0;
        while(start+10<=n){
            string curr = s.substr(start,10);
            //cout<<curr<<endl;
            if(memo.find(curr)==memo.end()){
                memo.insert(curr);
            }
            else{
                rep.insert(curr);
                
            }
            start++;
            
            
        }
        for(auto ones:rep){
            ans.push_back(ones);
        }
        
        
        
        
        
        return ans;
    }
};
