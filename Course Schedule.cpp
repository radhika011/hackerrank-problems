




class Solution {
public:
    /*
    There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.
    
    
    */
   
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses,0);
        unordered_map<int,vector<int>> adjList;
        int n_edges = prerequisites.size();
        for(int i = 0;i<n_edges;i++){
            int from = prerequisites[i][0];
            int to = prerequisites[i][1];
            indegree[to] +=1;
            adjList[prerequisites[i][0]].push_back(prerequisites[i][1]);
            
            
        }
        
        set<int> taken;
         
        while(taken.size()!=numCourses){
           bool flag = false;
           for(int i = 0;i<numCourses;i++){
               if(indegree[i]==0&&taken.find(i)==taken.end()){
                   flag = true;
                   for(int j = 0;j<adjList[i].size();j++){
                       indegree[adjList[i][j]] -=1;
                   }
                   taken.insert(i);
               }
           }
            if(!flag) return false;
            
        }
        return true;
    }
};
