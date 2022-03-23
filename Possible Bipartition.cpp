/*


We want to split a group of n people (labeled from 1 to n) into two groups of any size. Each person may dislike some other people, and they should not go into the same group.

Given the integer n and the array dislikes where dislikes[i] = [ai, bi] indicates that the person labeled ai does not like the person labeled bi, return true if it is possible to split everyone into two groups in this way.

*/





class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        unordered_map<int,vector<int>> graph;
        
        for(int i = 0;i<n;i++){
            vector<int> curr;
            graph[i]  = curr;
        }
        
        for(int i = 0;i<dislikes.size();i++){
            graph[dislikes[i][0]].push_back(dislikes[i][1]);
            graph[dislikes[i][1]].push_back(dislikes[i][0]);
        }
       // cout<<"here"<<endl;
        n = graph.size();
         set<pair<int,char>> visited;
         unordered_set<int> red;
        unordered_set<int> blue;
        for(int i = 0;i<n;i++){
            if(visited.find({i,'R'})!=visited.end()||visited.find({i,'B'})!=visited.end()) continue; 
           
        queue<pair<int,char>> q;
        q.push({i,'R'});
       
        while(!q.empty()){
            pair<int,char> p = q.front();
            q.pop();
            int curr = p.first;
            if(visited.find({curr,p.second})!=visited.end()) continue;
            char comp = p.second=='R'?'B':'R';
            if(visited.find({curr,comp})!=visited.end()) return false;
            char color = '_';
            if(p.second=='R'){
                color = 'B';
            }
            else{
                color = 'R';
            }
            for(int i = 0;i<graph[curr].size();i++){
                int child = graph[curr][i];
                if(color=='R'&&blue.find(child)!=blue.end()) return false;
                if(color=='B'&&red.find(child)!=red.end()) return false;
                if(color=='R'){
                    q.push({child,'R'});
                    red.insert(child);
                    
                    
                }
                else{
                    q.push({child,'B'});
                    blue.insert(child);
                }
            }
            
            visited.insert({curr,p.second});
            
            
            
            
            
        }
        }
        
        return true;
    }
};
