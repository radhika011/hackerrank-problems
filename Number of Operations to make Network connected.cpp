/*

There are n computers numbered from 0 to n-1 connected by ethernet cables connections forming a network where connections[i] = [a, b] represents a connection between computers a and b. Any computer can reach any other computer directly or indirectly through the network.

Given an initial computer network connections. You can extract certain cables between two directly connected computers, and place them between any pair of disconnected computers to make them directly connected. Return the minimum number of times you need to do this in order to make all the computers connected. If it's not possible, return -1. 

CONSIDER TEST CASE -
N=5
EDGES = [[0,1],[1,2],[2,0],[3,4]]


*/





class Solution {
public:
    
    int getAbsParent(int v, vector<int>& parent){
        if(parent[v]==-1) return v;
        return parent[v] = getAbsParent(parent[v],parent);
    }
    void unionize(int p1,int p2,vector<int>& parent,vector<int>& rank){
        if(p1==p2) return;
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
    
    
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        int ncon = connections.size();
        if(ncon<n-1) return -1;
        vector<int> parent(n,-1);
        vector<int> rank(n,0);
        int extraEdges = 0;
        for(int i = 0;i<ncon;i++){
            int p1 = getAbsParent(connections[i][0],parent);
            int p2 = getAbsParent(connections[i][1],parent);
            if(p1==p2){
                extraEdges++;
            }
            unionize(p1,p2,parent,rank);
        }
        unordered_map<int,int> umap;
        int comps = 0;
        for(int i =0;i<n;i++){
            int p = getAbsParent(i,parent);
            if(p==-1) comps++;
            umap[p]+=1;
        }
        comps+=umap.size();
        int req = --comps;
       // cout<<ncon<<" "<<seen.size()<<" "<<req<<endl;
        //cout<<extraEdges<<endl;
        if(extraEdges<req) return -1;
        else return req;
    }
};
