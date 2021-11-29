/*

In this problem, a tree is an undirected graph that is connected and has no cycles.

You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the graph.

Return an edge that can be removed so that the resulting graph is a tree of n nodes. If there are multiple answers, return the answer that occurs last in the input.




*/






class Solution {
public:
    vector<vector<int>> ans;
    
    int getAbsParent(vector<int> parent,int v){
        if(parent[v]==-1) return v;
        return parent[v] = getAbsParent(parent,parent[v]);
    }
    
    void unionize(vector<int>& parent,vector<int>& rank,int p1,int p2){
        if(rank[p1]>rank[p2]){  //attach p2 to p1
            parent[p2] = p1;
        }
        else if(rank[p1]<rank[p2]){ //attach p1 to p2
            parent[p1] = p2;
        }
        else{
            parent[p1] =p2; //attach p1 to p2
            rank[p2]+=1; //increment rank of p2
        }
        
        
    }
    
    void isCyclic(vector<vector<int>> edges,vector<int> parent,vector<int> rank){
        int n = edges.size();
        for(int i =0;i<n;i++){
            int p1 = getAbsParent(parent,edges[i][0]);
            int p2 = getAbsParent(parent,edges[i][1]);
            //cout<<p1<<" "<<p2<<endl;
            if(p1==p2){
                //cout<<"here"<<endl;
                vector<int> curr(2);
                curr[0] = edges[i][0];
                curr[1] = edges[i][1];
                ans.push_back(curr);
            }
            else unionize(parent,rank,p1,p2);
        }
        
        
    }
    
    
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n,-1);
        vector<int> rank(n,0);
        for(int i =0;i<n;i++){
            edges[i][0]-=1;
            edges[i][1]-=1;
        }
        isCyclic(edges,parent,rank);
        for(int i =0;i<ans.size();i++){
            //cout<<ans[i][0]<<" ";
             //cout<<ans[i][1]<<endl;
        }
        for(int i =0;i<ans.size();i++){
            ans[i][0]+=1;
            ans[i][1]+=1;
        }
        return ans[ans.size()-1];
    }
};
