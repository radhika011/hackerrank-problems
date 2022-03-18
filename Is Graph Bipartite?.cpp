/*
There is an undirected graph with n nodes, where each node is numbered between 0 and n - 1. You are given a 2D array graph, where graph[u] is an array of nodes that node u is adjacent to. More formally, for each v in graph[u], there is an undirected edge between node u and node v. The graph has the following properties:

There are no self-edges (graph[u] does not contain u).
There are no parallel edges (graph[u] does not contain duplicate values).
If v is in graph[u], then u is in graph[v] (the graph is undirected).
The graph may not be connected, meaning there may be two nodes u and v such that there is no path between them.
A graph is bipartite if the nodes can be partitioned into two independent sets A and B such that every edge in the graph connects a node in set A and a node in set B.

Return true if and only if it is bipartite.



*/





class Solution {
public:
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
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
