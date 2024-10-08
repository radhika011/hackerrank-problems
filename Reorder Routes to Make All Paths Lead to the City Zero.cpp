/*
There are n cities numbered from 0 to n - 1 and n - 1 roads such that there is only one way to travel between two different cities (this network form a tree). Last year, The ministry of transport decided to orient the roads in one direction because they are too narrow.

Roads are represented by connections where connections[i] = [ai, bi] represents a road from city ai to city bi.

This year, there will be a big event in the capital (city 0), and many people want to travel to this city.

Your task consists of reorienting some roads such that each city can visit the city 0. Return the minimum number of edges changed.

It's guaranteed that each city can reach city 0 after reorder.

 



*/






class Solution {
public:
    set<pair<int,int>> edges;
    unordered_map<int,vector<int>> neighbours;
    int ans;
    unordered_set<int> visited;
    
    void dfs(int curr){
        visited.insert(curr);
        for(int i = 0;i<neighbours[curr].size();i++){
            if(edges.find({neighbours[curr][i],curr})==edges.end()&&visited.find(neighbours[curr][i])==visited.end()){
                ans++;
            }
            
            if(visited.find(neighbours[curr][i])==visited.end()) dfs(neighbours[curr][i]);
        }
    }
    
    
    
    
    int minReorder(int n, vector<vector<int>>& connections) {
        this->ans = 0;
        int e = connections.size();
        unordered_map<int,vector<int>> neighbours;
        set<pair<int,int>> edges;
        for(int i =0;i<e;i++){
            edges.insert({connections[i][0],connections[i][1]});
            neighbours[connections[i][1]].push_back(connections[i][0]);
            neighbours[connections[i][0]].push_back(connections[i][1]);
            
        }
        this->edges = edges;
        this->neighbours = neighbours;
        unordered_set<int> visited;
        this->visited = visited;
        
        dfs(0);
        
        
        
        return ans;
    }
};
