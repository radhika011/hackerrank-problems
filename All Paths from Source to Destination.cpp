/*

Given a directed acyclic graph (DAG) of n nodes labeled from 0 to n - 1, find all possible paths from node 0 to node n - 1 and return them in any order.

The graph is given as follows: graph[i] is a list of all nodes you can visit from node i (i.e., there is a directed edge from node i to node graph[i][j]).


*/
class Solution {
public:
    vector<vector<int>> ans;
    void countPaths(vector<vector<int>>& graph,int target,int source,vector<int> currPath){
        if(source==target){
            //currPath.push_back(target);
            ans.push_back(currPath);
            return;
        }
        int sum = 0;
        for(int i =0;i<graph[source].size();i++){
            vector<int> temp = currPath;
            temp.push_back(graph[source][i]);
            countPaths(graph,target,graph[source][i],temp);
        }
       
    }
    
    
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int source = 0;
        int target = graph.size()-1;
        vector<int> currPath;
        currPath.push_back(0);
        countPaths(graph,target,source,currPath);
        //cout<<paths<<endl;
        
        
        return ans;
        
    }
};
