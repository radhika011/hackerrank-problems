/*

You are given a positive integer n representing the number of nodes of a Directed Acyclic Graph (DAG). The nodes are numbered from 0 to n - 1 (inclusive).

You are also given a 2D integer array edges, where edges[i] = [fromi, toi] denotes that there is a unidirectional edge from fromi to toi in the graph.

Return a list answer, where answer[i] is the list of ancestors of the ith node, sorted in ascending order.

A node u is an ancestor of another node v if u can reach v via a set of edges.




*/






class Solution {
public:
    
    
    
    int getMin(vector<int> indegree){
        for(int i =0;i<indegree.size();i++){
            if(indegree[i]==0) return i;
        }
        
        return -1;
        
    }
    
    
    
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        int e = edges.size();
        unordered_map<int,vector<int>> adjList;
        vector<int> indegree(n,0);
        vector<set<int>> ans(n);
         vector<vector<int>> finalAns(n);
        for(int i = 0;i<e;i++){
            int from = edges[i][0];
            int to = edges[i][1];
            adjList[from].push_back(to);
            indegree[to]+=1;
        }
        unordered_set<int> visited;
        while(visited.size()!=n){
            int next = getMin(indegree);
            if(next==-1){
                return finalAns;
            }
            visited.insert(next);
            indegree[next] = -1;
            set<int> currAnc = ans[next];
            
            
           
            for(int i = 0;i<adjList[next].size();i++){
                int v = adjList[next][i];
                indegree[v]-=1;
                for(auto it = currAnc.begin();it!=currAnc.end();it++){
                    ans[v].insert(*it);
                }
                ans[v].insert(next);
            }
            
        }
       
            for(int i = 0;i<n;i++){
                set<int> curr = ans[i];
                vector<int> converted(curr.begin(),curr.end());
                finalAns[i] = converted;
            }
        return finalAns;
    }
};
