/*

A gene string can be represented by an 8-character long string, with choices from 'A', 'C', 'G', and 'T'.

Suppose we need to investigate a mutation from a gene string start to a gene string end where one mutation is defined as one single character changed in the gene string.

For example, "AACCGGTT" --> "AACCGGTA" is one mutation.
There is also a gene bank bank that records all the valid gene mutations. A gene must be in bank to make it a valid gene string.

Given the two gene strings start and end and the gene bank bank, return the minimum number of mutations needed to mutate from start to end. If there is no such a mutation, return -1.

Note that the starting point is assumed to be valid, so it might not be included in the bank.





*/




class Solution {
public:
    vector<char> possible = {'A','C','G','T'};
    
    
    
    void dfs(string curr,queue<string>& q,unordered_set<string>&valids,int ind){
        if(ind==curr.size()) return;
         
        for(int i = 0;i<possible.size();i++){
            if(curr[ind]!=possible[i]){
                string spawn = curr;
                spawn[ind] = possible[i];
                //cout<<spawn<<endl;
                if(valids.find(spawn)==valids.end()) continue;
                q.push(spawn);
               
            }
        }
        dfs(curr,q,valids,ind+1);
        
    }
    
    
    
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> valids;
        for(int i = 0;i<bank.size();i++){
            valids.insert(bank[i]);
        }
        queue<string> q;
        q.push(start);
        unordered_set<string> visited;
        int steps = 0;
        while(!q.empty()){
           
            int temp = q.size();
            for(int i = 0;i<temp;i++){
                 string curr = q.front();
                 q.pop();
                if(curr==end) return steps;
                 if(visited.find(curr)!=visited.end()) continue;
                 dfs(curr,q,valids,0);
                 visited.insert(curr);
            }
             steps++;
           
        }
        
        return -1;
        
    }
}; 
