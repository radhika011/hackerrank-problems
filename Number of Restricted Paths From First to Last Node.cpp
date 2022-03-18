/*
There is an undirected weighted connected graph. You are given a positive integer n which denotes that the graph has n nodes labeled from 1 to n, and an array edges where each edges[i] = [ui, vi, weighti] denotes that there is an edge between nodes ui and vi with weight equal to weighti.

A path from node start to node end is a sequence of nodes [z0, z1, z2, ..., zk] such that z0 = start and zk = end and there is an edge between zi and zi+1 where 0 <= i <= k-1.

The distance of a path is the sum of the weights on the edges of the path. Let distanceToLastNode(x) denote the shortest distance of a path between node n and node x. A restricted path is a path that also satisfies that distanceToLastNode(zi) > distanceToLastNode(zi+1) where 0 <= i <= k-1.

Return the number of restricted paths from node 1 to node n. Since that number may be too large, return it modulo 109 + 7.




*/






typedef long long ll;
class Solution {
public:
    vector<int> dist;
    unordered_map<int,vector<pair<int,int>>> graph;
    ll ans;
    int n;
     int mod = pow(10,9)+7;
    vector<ll> memo;
    int dfs(int curr){
        if(memo[curr]!=-1) return memo[curr];
        if(curr==n-1){
            
            return 1;
        }
        ll path = 0;
        for(int i = 0;i<graph[curr].size();i++){
            if(dist[curr]>dist[graph[curr][i].first]){
                path+=(dfs(graph[curr][i].first)%mod);
            }
        }
        return memo[curr] = path%mod;
    }
    
    
    int findSmallest(vector<int> dist,unordered_set<int> processed){
        int n = dist.size();
        int minDist = INT_MAX;
        int ind = -1;
        for(int i =0;i<n;i++){
            if(dist[i]<minDist&&processed.find(i)==processed.end()){
                minDist = dist[i];
                ind = i;
            }
        }
        return ind;
    }
    
    
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<pair<int,int>>> graph;
        for(int i = 0;i<edges.size();i++){
            int from = edges[i][0]-1;
            int to = edges[i][1]-1;
            int wt = edges[i][2];
            graph[from].push_back({to,wt});
            graph[to].push_back({from,wt});
        }
        vector<int> dist(n,INT_MAX);
        dist[n-1] = 0;
        unordered_set<int> processed;
        while(true){
            int next = findSmallest(dist,processed);
            if(next==-1) break;
            for(int i = 0;i<graph[next].size();i++){
                int dest = graph[next][i].first;
                int wt = graph[next][i].second;
                int newDist = dist[next]+wt;
                if(dist[dest]>newDist){
                    dist[dest] = newDist;
                }
            }
            processed.insert(next);
        }
        this->graph = graph;
        this->dist = dist;
        this->ans = 0;
        this->n = n;
         vector<ll>memo(n,-1);
        this->memo = memo;
       
        ll answer = dfs(0);
        return answer%mod;
        
    }
};
