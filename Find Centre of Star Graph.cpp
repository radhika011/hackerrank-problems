/*
There is an undirected star graph consisting of n nodes labeled from 1 to n. A star graph is a graph where there is one center node and exactly n - 1 edges that connect the center node with every other node.

You are given a 2D integer array edges where each edges[i] = [ui, vi] indicates that there is an edge between the nodes ui and vi. Return the center of the given star graph.

BRUH



*/




class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int p1 = edges[0][0];
        int p2 = edges[0][1];
        if(edges[1][0]==p1||edges[1][1]==p1){
            return p1;
        }
        return p2;
    }
};
