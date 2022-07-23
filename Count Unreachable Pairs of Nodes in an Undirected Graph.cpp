/*



You are given an integer n. There is an undirected graph with n nodes, numbered from 0 to n - 1. You are given a 2D integer array edges where edges[i] = [ai, bi] denotes that there exists an undirected edge connecting nodes ai and bi.

Return the number of pairs of different nodes that are unreachable from each other.


*/





typedef long long ll;
class Solution {
public:
    unordered_map<int,vector<int>> graph;
    
    void visit(vector<int>& visited,int curr,int& size){
        
        size++;
        visited[curr] = 1;
        for(int i =0;i<graph[curr].size();i++){
            if(visited[graph[curr][i]]!=1) visit(visited,graph[curr][i],size);
        }
        
        
        
    }
    
    
    
    long long countPairs(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> graph;
        for(int i =0;i<edges.size();i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        this->graph = graph;
        vector<int> visited(n,0);
        vector<int> componentSizes;
        int comps = 0;
        for(int i =0;i<n;i++){
            if(visited[i]==0){
                int size = 0;
                visit(visited,i,size);
                comps++;
                componentSizes.push_back(size);
            }
        }
        ll ans = 0;
        for(int i =0;i<componentSizes.size();i++){
           ll unreach = n-componentSizes[i];
           ans+=(unreach*componentSizes[i]);
            
        }
        return ans/2;
        
    }
};
