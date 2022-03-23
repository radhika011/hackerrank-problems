/*
You are given an array of words where each word consists of lowercase English letters.

wordA is a predecessor of wordB if and only if we can insert exactly one letter anywhere in wordA without changing the order of the other characters to make it equal to wordB.

For example, "abc" is a predecessor of "abac", while "cba" is not a predecessor of "bcad".
A word chain is a sequence of words [word1, word2, ..., wordk] with k >= 1, where word1 is a predecessor of word2, word2 is a predecessor of word3, and so on. A single word is trivially a word chain with k == 1.

Return the length of the longest possible word chain with words chosen from the given list of words.




*/

//TLE for last test case


class Solution {
public:
    
    
    
    bool isPredecessor(string& s1,string& s2){
        if(s1.size()!=(s2.size()-1)) return false;
        int j = 0;
        bool flag = true;
        for(int i = 0;i<s1.size();){
            if(s1[i]!=s2[j]&&flag){
                flag = false;
                j++;
                continue;
            }
            if(s1[i]!=s2[j]) return false;
            i++;
            j++;
        }
        return true;
    }
    
    
    
    
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        unordered_map<string,vector<string>> graph;
        for(int i = 0;i<n;i++){
            string curr = words[i];
            //cout<<"curr:"<<curr<<endl;
            for(int j = 0;j<n;j++){
                if(i!=j){
                    bool check = isPredecessor(curr,words[j]);
                    if(check){
                        graph[curr].push_back(words[j]);
                        //cout<<words[j]<<" ";
                    }
                    
                }
            }
           // cout<<endl;
        }
        
        int ans = 1;
        set<string> visited;
        for(int i = 0;i<n;i++){
            string curr = words[i];
            if(visited.find(curr)!=visited.end()) continue;
            queue<string> q;
            q.push(curr);
            int steps = 0;
            while(!q.empty()){
                int temp = q.size();
                for(int i =0;i<temp;i++){
                   
                    string popped = q.front();
                     visited.insert(popped);
                     //cout<<popped<<endl;
                    q.pop();
                    for(int j = 0;j<graph[popped].size();j++){
                        q.push(graph[popped][j]);
                        //cout<<"neighbour:"<<graph[curr][j]<<endl;
                    }
                }
                //cout<<q.size()<<endl;
                steps++;
            }
            ans = max(ans,steps);
            
        }
        
        return ans;
    }
};
