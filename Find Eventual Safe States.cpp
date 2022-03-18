/*
There is a directed graph of n nodes with each node labeled from 0 to n - 1. The graph is represented by a 0-indexed 2D integer array graph where graph[i] is an integer array of nodes adjacent to node i, meaning there is an edge from node i to each node in graph[i].

A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node.

Return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.





*/




class Solution {
public:
    vector<vector<int>> graph;
   
    void dfs(int curr,unordered_set<int> visited, vector<int>& memo){
        if(memo[curr]!=-1) return;
        bool flag = true;
       
        if(visited.find(curr)!=visited.end()){
            
            memo[curr] = 0;
            //cout<<curr<<" "<<memo[curr]<<endl;
            return;
        }
         //cout<<curr<<endl;
        visited.insert(curr);
        for(int i =0;i<graph[curr].size();i++){
            dfs(graph[curr][i],visited,memo);
            //cout<<graph[curr][i]<<" "<<memo[graph[curr][i]]<<endl;
            if(memo[graph[curr][i]]==0){
                flag = false;
            }
        }
        
        if(!flag){
            memo[curr] = 0;
           
        }
        else memo[curr] = 1;
        //cout<<curr<<" "<<memo[curr]<<endl;
        
    }
    
    
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        this->graph = graph;
        int n = graph.size();
        vector<int> memo(n,-1);
        
        for(int i = 0;i<n;i++){
            if(graph[i].size()==0){
                memo[i] = 1;
            }
        }
        for(int i = 0;i<n;i++){
            if(memo[i]==-1){
                unordered_set<int> visited;
                dfs(i,visited,memo);
            }
        }
         vector<int> ans;
        for(int i = 0;i<n;i++){
            //cout<<memo[i]<<endl;
            if(memo[i]==1) ans.push_back(i);
        }
        return ans;
    }
}; 
