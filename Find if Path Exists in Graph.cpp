/*
There is a bi-directional graph with n vertices, where each vertex is labeled from 0 to n - 1 (inclusive). The edges in the graph are represented as a 2D integer array edges, where each edges[i] = [ui, vi] denotes a bi-directional edge between vertex ui and vertex vi. Every vertex pair is connected by at most one edge, and no vertex has an edge to itself.

You want to determine if there is a valid path that exists from vertex start to vertex end.

Given edges and the integers n, start, and end, return true if there is a valid path from start to end, or false otherwise.

*/


class Solution {
public:
    
    int getAbsParent(int v,vector<int>& parent){
        if(parent[v]==-1) return v;
        return parent[v] = getAbsParent(parent[v],parent);
    }
    
    void unionize(vector<int>& parent,vector<int>& rank,int p1,int p2){
        if(rank[p1]>rank[p2]){
            parent[p2] = p1;
        }
        else if(rank[p1]<rank[p2]){
            parent[p1] = p2;
        }
        else{
            parent[p1] = p2;
            rank[p2]+=1;
        }
    }
    
    
    void op(vector<vector<int>>& edges,vector<int>& parent,vector<int>& rank){
        int ne = edges.size();
        for(int i =0;i<ne;i++){
            int p1 = getAbsParent(edges[i][0],parent);
            int p2 = getAbsParent(edges[i][1],parent);
            if(p1!=p2) unionize(parent,rank,p1,p2);
        }
    }
    
    
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        vector<int> parent(n,-1);
        vector<int> rank(n,0);
        op(edges,parent,rank);
        int ps = getAbsParent(start,parent);
        int pe = getAbsParent(end,parent);
        if(ps==pe) return true;
        return false;
    }
};
