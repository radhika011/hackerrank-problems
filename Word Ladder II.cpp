
/*

A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return all the shortest transformation sequences from beginWord to endWord, or an empty list if no such sequence exists. Each sequence should be returned as a list of the words [beginWord, s1, s2, ..., sk].

Why does this give TLE?


*/




class Solution {
public:
    
    
    
    
    bool check(string s1,string s2){
        int n = s1.size();
        bool one = false;
        for(int i =0;i<n;i++){
            if(one&&s1[i]!=s2[i]){
                return false;
            }
            if(s1[i]!=s2[i]) one = true;
        }
        return true;
    }
    
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        unordered_map<string,vector<string>> graph;
        for(int i =0;i<n;i++){
            string curr = wordList[i];
            
            for(int j = i+1;j<n;j++){
                bool edgers = check(curr,wordList[j]);
                if(edgers){
                    graph[curr].push_back(wordList[j]);
                    graph[wordList[j]].push_back(curr);
                }
            }
        }
        if(graph.find(beginWord)==graph.end()){
            string curr = beginWord;
            for(int i =0;i<n;i++){
                bool edgers = check(curr,wordList[i]);
                if(edgers){
                    graph[curr].push_back(wordList[i]);
                    graph[wordList[i]].push_back(curr);
                }
                
            }
        }
        
        queue<pair<string,pair<vector<string>,unordered_set<string>>>> q;
        vector<vector<string>> ans;
        int minSize = INT_MAX;
        unordered_set<string> vis;
        q.push({beginWord,{{},vis}});
        while(!q.empty()){
            string curr = q.front().first;
            vector<string> path = q.front().second.first;
            unordered_set<string> visited = q.front().second.second;
            q.pop();
            if(curr==endWord){
                path.push_back(endWord);
                if(minSize<path.size()) break;
                ans.push_back(path);
                if(minSize>path.size()){
                    minSize = path.size();
                }
                continue;
            }
            
            path.push_back(curr);
            visited.insert(curr);
            for(int i = 0;i<graph[curr].size();i++){
                if(visited.find(graph[curr][i])==visited.end()) q.push({graph[curr][i],{path,visited}});
            }
        }
       
        return ans;
    }
};
