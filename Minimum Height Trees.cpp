/*

A tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.

Given a tree of n nodes labelled from 0 to n - 1, and an array of n - 1 edges where edges[i] = [ai, bi] indicates that there is an undirected edge between the two nodes ai and bi in the tree, you can choose any node of the tree as the root. When you select a node x as the root, the result tree has height h. Among all possible rooted trees, those with minimum height (i.e. min(h))  are called minimum height trees (MHTs).

Return a list of all MHTs' root labels. You can return the answer in any order.

The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.







*/


//BRUTE FORCE - DFS FOR EVERY VERTEX
class Solution {
public:
    
    int dfs(int i, unordered_map<int,vector<int>> graph,vector<bool>& visited){
        if(visited[i]==true) return 0;
        visited[i] = true;
        int currMax = INT_MIN;
        for(int j = 0;j<graph[i].size();j++){
            int curr = 1+dfs(graph[i][j],graph,visited);
            if(curr>currMax){
                currMax = curr;
            }
        }
        return currMax;
        
        
        
    }
    
    
    
    
    
    
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> graph;
        int n_edges = n-1;
        for(int i =0;i<n_edges;i++){
            int from = edges[i][0];
            int to = edges[i][1];
            graph[from].push_back(to);
            graph[to].push_back(from);
        }
        vector<int> ans;
        int minHeight = INT_MAX;
        for(int i =0;i<n;i++){
            vector<bool> visited(n,false);
            
            int currHeight = dfs(i,graph,visited);
            //cout<<i<<" "<<currHeight<<endl;
            if(currHeight<=minHeight){
                if(currHeight<minHeight){
                    ans.clear();
                }
                ans.push_back(i);
                minHeight = currHeight;
            }
        }
        
        
        
        
        
        return ans;
        
    }
};
