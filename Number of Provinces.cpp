/*

There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.



*/






class Solution {
public:
    
    void unionize(vector<int>& parent,vector<int>& rank, int p1,int p2){
        if(rank[p1]>rank[p2]){ //attach p2 to p1
            parent[p2] = p1;
        }
        else if(rank[p1]<rank[p2]){
            parent[p1] = p2;         //attach p1 to p2
        }
        else{
            parent[p1] = p2;      //attach p1 to p2
            rank[p2]+=1;            //increment rank of p2
        }
        
        
    }
    
    
    int getAbsParent(vector<int>& parent,int v){
        if(parent[v]==-1) return v;
        return parent[v] = getAbsParent(parent,parent[v]);
    }
    
    
    void op(vector<int>& parent,vector<int>& rank,vector<vector<int>> isConnected){
        int n = isConnected.size();
        for(int i =0;i<n;i++){
            for(int j =0;j<n;j++){
                if(isConnected[i][j]==1&&i!=j){
                    int p1 = getAbsParent(parent,i);
                    int p2 = getAbsParent(parent,j);
                    if(p1!=p2){
                        unionize(parent,rank,p1,p2);
                    }
                    isConnected[j][i] = 0;
                }
            }
        }
        
        
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> parent(n,-1);
        vector<int> rank(n,0);
        op(parent,rank,isConnected);
        set<int> memo;
        int count = 0;
        for(int i =0;i<n;i++){
            int p = getAbsParent(parent,i);
            if(memo.find(p)==memo.end()){
                count++;
                memo.insert(p);
                
            }
        }
        return count;
        
    }
};
