
/*
A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.






*/


//Apparently not efficient enough - O(N^2*M)


class Solution {
public:
    
    unordered_map<string,vector<int>> counts;
    unordered_map<string,vector<string>> graph;
    bool check(string word1, string word2){
        /*
        vector<int> freq1 = counts[word1];
        vector<int> freq2 = counts[word2];
        int count = 0;
        for(int i = 0;i<128;i++){
            count+=abs(freq1[i]-freq2[i]);
            if(count>2) return false;
            
        }
        return true;
        */
        bool one = false;
        for(int i = 0;i<word1.size();i++){
            if(word1[i]!=word2[i]&&one) return false;
            else if(word1[i]!=word2[i]) one = true;
        }
        return true;
    }
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        
        vector<int> curr(128,0);
        for(int i = 0;i<beginWord.size();i++){
            curr[beginWord[i]]+=1;
        }
        counts[beginWord] = curr;
        for(int i = 0;i<wordList.size();i++){
            string word = wordList[i];
            vector<int> freq(128,0);
            for(int j =0;j<word.size();j++){
                freq[(int)word[j]]+=1;
            }
            counts[word] = freq;
        }
         //cout<<check("lgg","log")<<endl;
        
        for(auto it = counts.begin();it!=counts.end();it++){
            string word1 = it->first;
            vector<int> freq1 = it->second;
            vector<string> neighbours; 
            for(auto it1 = counts.begin();it1!=counts.end();it1++){
                string word2 = it1->first;
                vector<int> freq2 = it1->second;
                if(word1==word2) continue;
                if(check(word1,word2)){
                    neighbours.push_back(word2);
                }
            }
            graph[word1] = neighbours;
            
            /*
            cout<<word1<<endl;
            cout<<neighbours.size()<<endl;;
            for(int i = 0;i<neighbours.size();i++){
                cout<<neighbours[i]<<" ";
            }
            cout<<endl;
            */
        }
        if(graph.find(endWord)==graph.end()) return 0;
        queue<pair<string,int>> q;
        unordered_set<string> visited;
        q.push({beginWord,1});
        int minLevel = INT_MAX;
        visited.insert(beginWord);
        while(!q.empty()){
            string word = q.front().first;
            int level = q.front().second;
            q.pop();
            if(word==endWord){
                
                minLevel = min(minLevel,level);
                break;
            }
            //if(visited.find(word)!=visited.end()) continue;
           //cout<<word<<" "<<level<<endl;
            for(int i = 0;i<graph[word].size();i++){
                if(visited.find(graph[word][i])==visited.end())q.push({graph[word][i],level+1});
            }
            visited.insert(word);
            
        }
        if(minLevel==INT_MAX) return 0;
        return minLevel;
    }
}; 


//This is efficient enough, apparently
class Solution {
public:
    void generatePossible(string curr,int ind,queue<string>& q,unordered_set<string>& valid){
        if(curr.size()==ind){
            return;
        }
        char position = curr[ind];
        for(int i = 0;i<26;i++){
            char ch = char(97+i);
            if(ch!=position){
                string temp = curr;
                temp[ind] = ch;
                if(valid.find(temp)!=valid.end()){
                    q.push(temp);
                }
            }
        }
        generatePossible(curr,ind+1,q,valid);
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> valid{wordList.begin(),wordList.end()};
        queue<string> q;
        unordered_set<string> visited;
        int steps = 0;
        q.push(beginWord);
        while(!q.empty()){
            int temp = q.size();
            for(int i = 0;i<temp;i++){
                string curr = q.front();
                q.pop();
                if(curr==endWord) return steps+1;
                if(visited.find(curr)!=visited.end()) continue;
                generatePossible(curr,0,q,valid);
                visited.insert(curr);
            }
            steps++;
        }
        return 0;
    }
};
