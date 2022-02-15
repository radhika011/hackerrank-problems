/*
Given a binary string s and an integer k, return true if every binary code of length k is a substring of s. Otherwise, return false.

 



*/





class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.size();
        set<string> visited;
        int start = 0;
        int end = k-1;
        int zeros = 0;
        int ones = 0;
        while(end<n){
            
            visited.insert(s.substr(start,k));
            end++;
            start++;
        }
        /*
        for(auto it = visited.begin();it!=visited.end();it++){
            cout<<*it<<endl;
        }
        */
        if(visited.size()==(1<<k)) return true;
        return false;
    }
};
