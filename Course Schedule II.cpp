/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.

*/



class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> list;
        vector<int> indegree(numCourses,0);
        int n_edges = prerequisites.size();
        for(int i =0;i<n_edges;i++){
            int from = prerequisites[i][0];
            int to = prerequisites[i][1];
            list[from].push_back(to);
            indegree[to]++;
        }
        vector<int> ans;
        
        set<int> taken;
        while(taken.size()!=numCourses){
            bool flag = false;
            for(int i = 0;i<numCourses;i++){
                if(indegree[i]==0&&taken.find(i)==taken.end()){
                    flag = true;
                    for(int j =0;j<list[i].size();j++){
                        indegree[list[i][j]] -=1;
                    }
                    taken.insert(i);
                    ans.push_back(i);
                }
            }
            if(!flag){
                ans.clear();
                //cout<<"false"<<endl;
                return ans;
            }
        }
        reverse(ans.begin(),ans.end());
        // cout<<"true"<<endl;
        return ans;
    }
};
