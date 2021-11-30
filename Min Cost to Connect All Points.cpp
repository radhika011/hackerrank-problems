
/*


You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].

The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.

Return the minimum cost to make all points connected. All points are connected if there is exactly one simple path between any two points.



*/





class Solution {
public:
    
    vector<vector<int>> createGraph(vector<vector<int>>& points){
        int n = points.size();
        vector<vector<int>> adjList(n,vector<int>(3,0));
        for(int i = 0;i<n;i++){
            for(int j= i-1;j>=0;j--){
                int manhattan_dist = abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                vector<int> curr;
                curr.push_back(manhattan_dist);
                curr.push_back(i);
                curr.push_back(j);
                adjList.push_back(curr);
            }
        }
        return adjList;
    }
    
    int getAbsParent(vector<int>& parent,int v){
        if(parent[v]==-1) return v;
        return parent[v] = getAbsParent(parent,parent[v]);
    }
    
    void unionize(int p1,int p2,vector<int>&parent,vector<int>& rank){
        if(rank[p1]>rank[p2]){
            //attach p2 to p1
            parent[p2] = p1;
        }
        else if(rank[p1]<rank[p2]){
            //attach p1 to p2
            parent[p1] = p2;
        }
        else{
            parent[p1] = p2;
            rank[p2]+=1;
        }
    }
    
    
    int minCostConnectPoints(vector<vector<int>>& points) {
       int n = points.size();
        if(n==1) return 0;
        if(n==2) {
            return abs(points[0][0]-points[1][0])+abs(points[0][1]-points[1][1]);
        }
        vector<vector<int>> graph = createGraph(points);
       int n_edges = 0;
        sort(graph.begin(),graph.end());
        int minCost = 0;
        vector<int> parent(n,-1);
        vector<int> rank(n,0);
        for(auto edge:graph){
            int p1 = getAbsParent(parent,edge[1]);
            int p2 = getAbsParent(parent,edge[2]);
            if(p1==p2) continue;
            minCost+=edge[0];
            unionize(p1,p2,parent,rank);
            n_edges+=1;
            if(n_edges==n-1) return minCost;
        }
        return minCost;
    }
};
