
/*
There are n cities numbered from 0 to n-1. Given the array edges where edges[i] = [fromi, toi, weighti] represents a bidirectional and weighted edge between cities fromi and toi, and given the integer distanceThreshold.

Return the city with the smallest number of cities that are reachable through some path and whose distance is at most distanceThreshold, If there are multiple such cities, return the city with the greatest number.

Notice that the distance of a path connecting cities i and j is equal to the sum of the edges' weights along that path.


*/





class Solution {
public:
    vector<vector<pair<int,int>>> createAdjList(vector<vector<int>>& edges,int n){
        int n_edges = edges.size();
        vector<vector<pair<int,int>>> list;
        for(int i =0;i<n;i++){
            vector<pair<int,int>> curr;
            list.push_back(curr);
        }
        for(int i =0;i<n_edges;i++){
            int from = edges[i][0];
            int to = edges[i][1];
            int dist = edges[i][2];
            list[from].push_back({to,dist});
            list[to].push_back({from,dist});
        }
        return list;
    }
    
    
    int getMinDist(vector<int> distances,set<int> visited){
        int minimum = INT_MAX;
        int ind = -1;
        int n =distances.size();
        for(int i = 0;i<n;i++){
            if(visited.find(i)==visited.end()){
                //if it is not visited yet
                if(minimum>distances[i]){
                    ind = i;
                    minimum = distances[i];
                }
            }
        }
        return ind;
    }
    
    
    
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int,int>>> graph = createAdjList(edges,n);
        int minCity = -1;
        int minCount = INT_MAX;
        for(int k = 0;k<n;k++){
            vector<int> dist(n,INT_MAX);
            dist[k] = 0;
            set<int> visited;
            while(visited.size()!=n){
                int next = getMinDist(dist,visited);
                if(next==-1){
                    break;
                }
                for(int i = 0;i<graph[next].size();i++){
                    int dest = graph[next][i].first;
                    if(visited.find(dest)==visited.end()){
                        int curr_dist = graph[next][i].second;
                        int new_dist = dist[next]+curr_dist;
                        if(dist[dest]>new_dist){
                            dist[dest] = new_dist;
                        }
                    }
                    
                    
                }
                visited.insert(next);
            }
            int count = 0;
            for(int i = 0;i<n;i++){
               // cout<<dist[i]<<" ";
                if(dist[i]!=INT_MAX&&dist[i]<=distanceThreshold) count++;
            }
            //cout<<count;
            //cout<<endl;
            if(count<=minCount){
                minCount = count;
                minCity = k;
            }
            
            
        }
        return minCity;
        
        }
};
