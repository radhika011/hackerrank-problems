/*

There is a group of n people labeled from 0 to n - 1 where each person has a different amount of money and a different level of quietness.

You are given an array richer where richer[i] = [ai, bi] indicates that ai has more money than bi and an integer array quiet where quiet[i] is the quietness of the ith person. All the given data in richer are logically correct (i.e., the data will not lead you to a situation where x is richer than y and y is richer than x at the same time).

Return an integer array answer where answer[x] = y if y is the least quiet person (that is, the person y with the smallest value of quiet[y]) among all people who definitely have equal to or more money than the person x.


SIMPLE DFS TRAVERSAL - W MEMO


*/




class Solution {
public:
     vector<int> ans;
    unordered_map<int,int> umap;
    int rec( vector<int>& quiet,vector<vector<int>>& list,int curr){
        if(ans[curr]!=-1) return ans[curr];
       
        int minimum = curr;
        for(int i =0;i<list[curr].size();i++){
            int rmin = rec(quiet,list,list[curr][i]);
            if(quiet[minimum]>quiet[rmin]){
                minimum = rmin;
            }
        }
        ans[curr] = minimum;
        return ans[curr];
    }
    
    
    
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        
         int n = quiet.size();
        for(int i = 0;i<n;i++){
            umap[quiet[i]] = i;
        }
       
        vector<vector<int>> list(n);
        for(int i = 0;i<richer.size();i++){
            int from = richer[i][1];
            int to = richer[i][0];
            list[from].push_back(to);
        }
       for(int i =0;i<n;i++){
           ans.push_back(-1);
       }
        for(int i = 0;i<n;i++){
            if(ans[i]==-1){
            int minimum = rec(quiet,list,i);
            }
            
        }
        return ans;
    }
};
