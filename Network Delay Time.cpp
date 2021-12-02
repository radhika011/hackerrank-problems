/*

You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.

We will send a signal from a given node k. Return the time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.


*/

class Solution {
public:
    
    
    vector<vector<pair<int,int>>> createAdjList(vector<vector<int>>& times,int n){
        int n_edges = times.size();
       vector<vector<pair<int,int>>> list;
        for(int i = 0;i<n;i++){
            vector<pair<int,int>> curr;
            list.push_back(curr);
        }
        for(int i =0;i<n_edges;i++){
            int from = times[i][0]-1;
            int to = times[i][1]-1;
            int wts = times[i][2];
            list[from].push_back({to,wts});
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
    
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        set<int> visited;
        vector<int> distances(n,INT_MAX);
        distances[k-1] = 0;
        vector<vector<pair<int,int>>> graph = createAdjList(times,n);
        while(visited.size()!=n){
            int next = getMinDist(distances,visited);
            if(next==-1) return -1;
            for(int i =0;i<graph[next].size();i++){
                int to = graph[next][i].first;
                if(visited.find(to)==visited.end()){
                int dist = graph[next][i].second;
                int new_dist = distances[next]+dist;
                if(new_dist<distances[to]){
                    distances[to] = new_dist;
                }
                }
            }
            visited.insert(next);
        }
        int maximum = INT_MIN;
        for(int i = 0;i<n;i++){
            maximum = max(maximum,distances[i]);
        }
        return maximum;
    }
};
